#include "Cube.h"

float Cube::interside(const Rayon &ray, int dim, float offset) const {
    float t = -1;
    if (ray.Dir()[dim] < 0.00001 && ray.Dir()[dim] > -0.00001)return -1;
    t = (offset - ray.Origin()[dim]) / ray.Dir()[dim];
    if (t < 0)return -1;
    for (int d = 0; d < 3; d++) {
        if (d == dim)continue;
        float x = ray.Origin()[d] + t * ray.Dir()[d];
        if (x < -1 || x > 1)return -1;
    }
    return t;
}

bool Cube::intersect(const Rayon &ray, Point &pts) const {
    Rayon r = globalToLocal(ray).normalized();
    float mint = -1;
    float offsets[] = { -1, 1 };
    for (int d = 0; d < 3; d++) {
        for (int o = 0; o < 2; o++) {
            float t = interside(r, d, offsets[o]);
            if (t >= 0 && (mint < 0 || mint > t)) {
                mint = t;
            }
        }
    }

    if (mint >= 0) {
        pts = localToGlobal(r.Origin() + (r.Dir()) * mint);
        return true;
    }

    return false;
}

Rayon Cube::getNormal(const Point &pts, const Point &org) const {
    Point lp = globalToLocal(pts);
    Point lo = globalToLocal(org);
    Vector v(0, 0, 0);
    if (lp[0] > 0.999)v[0] = 1.0;
    else if (lp[0] < -0.999)v[0] = -1.0;
    else if (lp[1] > 0.999)v[1] = 1.0;
    else if (lp[1] < -0.999)v[1] = -1.0;
    else if (lp[2] > 0.999)v[2] = 1.0;
    else if (lp[2] < -0.999)v[2] = -1.0;
    if (lo[0] < 1 && lo[0] > -1 && lo[1] < 1 && lo[1] > -1 && lo[2] < 1 && lo[2] > -1)
        return localToGlobal(Rayon(lp, -v)).normalized();
    return localToGlobal(Rayon(lp, v)).normalized();

}

Point Cube::getTextureCoordinates(const Point& pts) const {
    Point lp = globalToLocal(pts);
    if (lp.X() > 0.999 || lp.X() < -0.999)
        return Point(lp.Z() / 2 + 0.5, lp.Y() / 2 + 0.5, 0);
    if (lp.Y() > 0.999 || lp.Y() < -0.999)
        return Point(lp.X() / 2 + 0.5, lp.Z() / 2 + 0.5, 0);
    if (lp.Z() > 0.999 || lp.Z() < -0.999)
        return Point(lp.X() / 2 + 0.5, lp.Y() / 2 + 0.5, 0);
    return Point(0, 0, 0);
}
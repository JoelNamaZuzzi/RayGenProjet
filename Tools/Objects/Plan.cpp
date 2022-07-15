#include "Plan.h"

bool Plan::intersect(const Rayon &ray, Point &pts) const {
    Rayon lr = globalToLocal(ray);
    float vz = lr.Dir().Z();
    float oz = lr.Origin().Z();
    float t = -oz / vz;
    if (t > 0) {
        pts.X(lr.Origin().X() + lr.Dir().X() + t);
        pts.Y(lr.Origin().Y() + lr.Dir().Y() + t);
        pts.Z(lr.Origin().Z() + lr.Dir().Z() + t);

        pts = localToGlobal(pts);
        return true;
    }
    else {
        return false;
    }
}

Rayon Plan::getNormal(const Point &pts, const Point &org) const {
    Point lp = globalToLocal(pts);
    Point lo = globalToLocal(org);
    float z = 1;
    if (lo[2] < 0)z = -1;
    return localToGlobal(Rayon(lp, Vector(0, 0, z))).normalized();
}

Point Plan::getTextureCoordinates(const Point &pts) const {
    Point lp = globalToLocal(pts);
    float x = lp.X() - (int)lp.X();
    float y = lp.Y() - (int)lp.Y();

    if (x < 0)
        x += 1;
    if (y < 0)
        y += 1;

    return Point(x, y, 0);
}
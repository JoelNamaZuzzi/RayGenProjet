#include "Cylinder.h"

bool Cylinder::intersect(const Rayon &ray, Point &pts) const {
    Rayon r = globalToLocal(ray).normalized();

    float a = r.Dir()[0] * r.Dir()[0] + r.Dir()[2] * r.Dir()[2];
    float b = 2 * (r.Dir()[0] * r.Origin()[0] + r.Dir()[2] * r.Origin()[2]);
    float c = r.Origin()[0] * r.Origin()[0] + r.Origin()[2] * r.Origin()[2] - 1.0;
    float delta = b * b - 4 * a * c;

    if (delta < 0)return false;

    float t;
    if (delta < 0.0001) {
        t = -b / (2 * a);
    }
    else {
        t = (-b - sqrt(delta)) / (2 * a);
        if (t < 0)t = (-b + sqrt(delta)) / (2 * a);
    }
    if (t < 0)return false;

    Point p = r.Origin() + (r.Dir() * t);
    pts = localToGlobal(p);
    return true;
}

Rayon Cylinder::getNormal(const Point& p, const Point& o) const {
    Point lp = globalToLocal(p);
    Point lo = globalToLocal(o);
    if (Vector((lo - Point(0, lo[1], 0))).norm() > 1)
        return localToGlobal(Rayon(lp, Vector(lp[0], 0, lp[2]))).normalized();
    return localToGlobal(Rayon(lp, Vector(-lp[0], 0, -lp[2]))).normalized();

}

Point Cylinder::getTextureCoordinates(const Point &pts) const{
    return { 0, 0, 0 }; 
}
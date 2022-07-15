#define _USE_MATH_DEFINES
#include <cmath>
#include "Sphere.h"
#include "../Vector.h"

bool Sphere::intersect(const Rayon &ray, Point &pts) const {
    Rayon r = globalToLocal(ray).normalized();

    float a = r.Dir().dot(r.Dir());
    float b = 2 * r.Dir().dot(r.Origin());
    float c = r.Origin().dot(r.Origin()) - 1.f;
    float delta = b * b - 4.f * a * c;

    if (delta < 0)
        return false;

    float t;
    if (delta < 0.0001f) {
        t = -b / (2.f * a);
    }
    else {
        t = (-b - sqrt(delta)) / (2.f * a);
        if (t < 0)
            t = (-b + sqrt(delta)) / (2.f * a);
    }
    if (t < 0.f)
        return false;

    Point p = r.Origin() + (r.Dir() * t);
    pts = localToGlobal(p);
    return true;
}

Rayon Sphere::getNormal(const Point &pts, const Point &org) const {
    Point lp = globalToLocal(pts);
    Point lo = globalToLocal(org);
    if (Vector((lo - Point(0, 0, 0))).norm() < 1)return localToGlobal(Rayon(lp, -lp)).normalized();
    return localToGlobal(Rayon(lp, lp)).normalized();
}

Point Sphere::getTextureCoordinates(const Point &pts) const {
    Point lp = globalToLocal(pts);
    float rho = std::sqrt(lp.dot(lp));
    float theta = std::atan2(lp.Y(), lp.X());
    float sigma = std::acos(lp.Z() / rho);
    float x = -theta / (2 * M_PI) + 0.5;
    float y = sigma / M_PI;
    return Point(x, y, 0);
}
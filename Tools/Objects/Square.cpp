#include "Square.h"

bool Square::intersect(const Rayon &ray, Point &pts) const {
    Rayon lr = globalToLocal(ray).normalized();
    if (lr.Dir()[2] < 0.0001 && lr.Dir()[2] > -0.0001)return false;
    if (lr.Dir()[2] * lr.Origin()[2] > 0)return false;
    float t = -lr.Origin()[2] / lr.Dir()[2];
    Point p = lr.Origin() + (lr.Dir() * t);
    if (p[0] < -1 || p[0] > 1 || p[1] < -1 || p[1] > 1)return false;
    pts = localToGlobal(p);
    return true;
}

Point Square::getTextureCoordinates(const Point &pts) const {
    Point rp = globalToLocal(pts);
    float x = rp.X() / 2.f + 0.5f;
    float y = rp.Y() / 2.f + 0.5f;
    return Point(x, y, 0.f);
}
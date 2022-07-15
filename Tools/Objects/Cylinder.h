#ifndef RAYGEN_CYLINDER_H
#define RAYGEN_CYLINDER_H

#include "../Object.h"
#include <vector>

class Cylinder : public Object {
    Cylinder(Vector trans, Vector rot, Vector sca, std::string n, std::vector<Material> m) : Object(trans, rot, sca, n, std::move(m)) {}

    Cylinder(Vector trans, Vector rot, Vector sca, std::vector<Material> m) : Object(trans, rot, sca, "cylinder", std::move(m)) {}

    bool intersect(const Rayon &ray, Point &impact) const override;

    Rayon getNormal(const Point &pts, const Point &org) const override;

    Point getTextureCoordinates(const Point &pts) const override;
};
#endif //RAYGEN_CYLINDER_H
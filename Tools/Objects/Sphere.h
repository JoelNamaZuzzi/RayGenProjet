#pragma once
#ifndef RAYGEN_SPHERE_H
#define RAYGEN_SPHERE_H

#include <utility>
#include "../Object.h"

class Sphere : public Object {
public:
    Sphere(Vector trans, Vector rot, Vector sca, std::string n, std::vector<Material> m) : Object(trans, rot, sca,
        std::move(n),
        std::move(m)) {}

    Sphere(Vector trans, Vector rot, Vector sca, std::vector<Material> m) : Object(trans, rot, sca, "sphere",
        std::move(m)) {}

    bool intersect(const Rayon &ray, Point &pts) const override;

    Rayon getNormal(const Point &pts, const Point &org) const override;

    Point getTextureCoordinates(const Point &pts) const override;
};

#endif //RAYGEN_SPHERE_H

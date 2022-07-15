#pragma once
#ifndef RAYGEN_PLAN_H
#define RAYGEN_PLAN_H

#include <utility>
#include "../Object.h"

class Plan :public Object {
public: 
    Plan(Vector trans, Vector rot, Vector sca, std::string n, std::vector<Material> m) : Object(trans, rot, sca, std::move(n), m) {}

    Plan(Vector trans, Vector rot, Vector sca, std::vector<Material> m) : Object(trans, rot, sca, "plan", std::move(m)) {}

    bool intersect(const Rayon &ray, Point &pts) const override;

    Rayon getNormal(const Point &pts, const Point &org) const override;

    Point getTextureCoordinates(const Point &pts) const override;
};
#endif //RAYGEN_PLAN_H
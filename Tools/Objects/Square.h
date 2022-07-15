#pragma once
#ifndef RAYGEN_SQUARE_H
#define RAYGEN_SQUARE_H

#include <utility>
#include"Plan.h"
#include"../Point.h"

class Square : public Plan {
public:
    Square(Vector trans, Vector rot, Vector sca, std::string n, std::vector<Material> m) : Plan(trans, rot, sca,
        std::move(n), m) {}

    Square(Vector trans, Vector rot, Vector sca, std::vector<Material> m) : Plan(trans, rot, sca, "square",
        std::move(m)) {}

    bool intersect(const Rayon &ray, Point &impact) const override;

    Point getTextureCoordinates(const Point &pts) const override;
};

#endif //RAYGEN_SQUARE_H

#pragma once
#ifndef RAYGEN_CAM_H
#define RAYGEN_CAM_H

#include <string>
#include <utility>
#include <vector>
#include "Entity.h"
#include "Rayon.h"
#include "Object.h"
#include "Scene.h"

class Camera : public Entity {
private:
    float focal;
    Scene scene;

    bool CloserThan(const Point &oldImpact, const Point &newImpact, const Vector &comparison) const;

public:


    Camera() = default;

    Camera(float foc, Scene s) : focal(foc), scene(std::move(s)), Entity() {}

    Camera(const float &foc,
        const int &h,
        Scene sce,
        const Point &pos,
        const Vector &rot)
        : focal(foc),
        scene(std::move(sce)),
        Entity(pos, rot, { 1, 1, 1 }) {}

    Camera(float foc, const Point pos, const Vector &rot, const Vector &sca) : focal(foc), Entity(pos, rot, sca) {}

    ~Camera() = default;

    Rayon getRay(float x, float y);

    std::string sceneName() const {
        return scene.getName();
    }

    void screenshot(const std::string &name, const int &height, const bool &displayShadows, const int &ssaa);

    Color getImpactColor(const Rayon &ray, Object *obj, const Point &impact, const bool &displayShadows);
};


#endif //RAYGEN_CAM_H
#pragma once
#ifndef RAYGEN_SCENE_H
#define RAYGEN_SCENE_H

#include <utility>
#include <vector>
#include <string>
#include "Color.h"
#include "Light.h"
#include "Object.h"

class Scene
{
private: 
	Color bgColor;
	Color ambCol;
	std::vector<Light *> lights;
	std::vector<Object *> objects;
	std::string name;
public: 
	Scene() = default;
	Scene(const Color &back, const Color &ambiant, std::vector<Light *> li, std::vector<Object *> obj, std::string _name) : bgColor(back), ambCol(ambiant), lights(std::move(li)), objects(std::move(obj)), name(std::move(_name)) {};
	Object *closer_intersected(const Rayon &ray, Point &pts) const;
	Color getBackground() const;
	Color getAmbiant() const;
	int nbLights() const;
	Light *getLight(int i) const;
	std::vector<Object *> getObjects() const;
	std::string getName() const;
};
#endif // RAYGEN_SCENE_H

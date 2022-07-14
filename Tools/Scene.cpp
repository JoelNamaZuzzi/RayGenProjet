#include "Scene.h"

Color Scene::getBackground() const {
	return bgColor;
}

Color Scene::getAmbiant() const {
	return ambCol;
}

int Scene::nbLights() const {
	return lights.size();
}

Light *Scene::getLight(int i) const {
	return lights[i];
}

std::vector<Object *> Scene::getObjects() const {
	return objects;
}

std::string Scene::getName() const {
	return name;
}

Object *Scene::closer_intersected(const Rayon &ray, Point &pts) const {
	throw "Implem";
}
#pragma once
#ifndef RAYGEN_CUBE_H
#define RAYGEN_CUBE_H

#include <utility>
#include "../Object.h"

class Cube : public Object {
private: 
	float interside(const Rayon &ray, int dim, float offset) const;
public: 
	Cube(Vector trans, Vector rot, Vector sca, std::string name, std::vector<Material> mat): Object(trans, rot,sca,std::move(name),mat){}
	Cube(Vector trans, Vector rot, Vector sca, std::vector<Material> mat) : Object(trans, rot, sca, "cube", std::move(mat)) {}
	bool intersect(const Rayon &ray, Point &pts) const override;
	Rayon getNormal(const Point &pts, const Point &org) const override;
	Point getTextureCoordinates(const Point &pts) const override;
};

#endif //RAYGEN_CUBE_H

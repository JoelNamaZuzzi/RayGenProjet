#pragma once
#ifndef RAYGEN_RAYON_H
#define RAYGEN_RAYON_H

#include <iostream>
#include "Point.h"
#include "Vector.h"

class Rayon {
private:
	Point origin;
	Vector dir;
public:
	Rayon(float orx, float ory, float orz, float dirx, float diry, float dirz) : origin(orx, ory, orz), dir(dirx, diry, dirz) {};

	Rayon(Point or, Vector di) : origin(or), dir(di) {};

	Point Origin() const;

	void Origin(Point pts);

	Vector Dir() const;

	void Dir(Vector vec);

	Rayon normalized();
};
std::ostream &operator<<(std::ostream &os, const Rayon &ray);
#endif //RAYGEN_RAYON_H

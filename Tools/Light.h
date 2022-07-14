#pragma once
#ifndef RAYGEN_LIGHT_H
#define RAYGEN_LIGHT_H

#include "Entity.h"
#include "Rayon.h"
#include "Point.h"
#include "Vector.h"
#include "Color.h"

class Light : public Entity {
private : 
	Color _id;
	Color _is;
public: 
	Light(): Entity() {}
	Light(Color idiff, Color ispec, Point pos, Vector rot, Vector sca) : _id(idiff), _is(ispec), Entity(pos, rot, sca) {};
	Color id() const;
	Color is() const;
	Vector getVectorToLight(const Point &pts) const;
	Vector getVectorFromLight(const Point &pts) const;
};
#endif //RAYGEN_LIGHT_H
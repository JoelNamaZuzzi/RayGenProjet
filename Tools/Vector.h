#pragma once

#ifndef RAYGEN_VECTOR_H
#define RAYGEN_VECTOR_H

#include <iostream>
#include "Point.h"

class Vector : public Point{
public:
	Vector() : Point(0, 0, 0) {};
	Vector(const float &x, const float &y, const float &z) : Point(x, y, z) {};
	Vector(const Vector &v) : Point(v) {};
	Vector(const Point &p) : Point(p) {};

	float norm() const;

	Vector normalized() const;

	Vector operator*(const float factor) const {
		return { this->mx * factor, this->my * factor, this->mz * factor };
	}
};

std::ostream &operator<<(std::ostream &os, const Vector &v);

#endif //RAYGEN_VECTOR_H
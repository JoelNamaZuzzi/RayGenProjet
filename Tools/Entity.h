#pragma once
#ifndef RAYGEN_ENTITY_H
#define RAYGEN_ENTITY_H

#include <iostream>
#include "Rayon.h"
#include "Matrix.h"
#include "Vector.h"

class Entity {
protected:
	Matrix neo = Matrix::identity();
	Matrix neoInv = Matrix::identity();
public:

	Entity() = default;
	Entity(Vector pos, Vector rot, Vector size) {
		neo = Matrix();
		scaling(size);
		rotate(rot);
		translate(pos);
	}

	~Entity() = default;

	void translate(Vector Vectrans);
	void rotateX(float deg);
	void rotateY(float deg);
	void rotateZ(float deg);
	void rotate(Vector deg);
	void scaling(Vector sca);

	Point localToGlobal(const Point &pts) const;
	Vector localToGlobal(const Vector &vec) const;
	Rayon localToGlobal(const Rayon &ray) const;
	Point globalToLocal(const Point &pts) const;
	Vector globalToLocal(const Vector &vec) const;
	Rayon globalToLocal(const Rayon &ray) const;
	Matrix getMatrix() const;
	Vector position() const;
};

std::ostream& operator<<(std::ostream& os, const Entity& vec);

#endif //RAYGEN_ENTITY_H
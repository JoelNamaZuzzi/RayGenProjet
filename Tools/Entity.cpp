#define _USE_MATH_DEFINES

#include <cmath>
#include "Entity.h"

void Entity::translate(const Vector vec) {
	Matrix mat;

	mat(0, 3) = vec[0];
	mat(1, 3) = vec[1];
	mat(2, 3) = vec[2];
	neo = mat * neo;
	neoInv = neo.inverse();
}

void Entity::rotateX(const float deg) {
	Matrix mat;

	float rad = deg * M_PI / 180;
	float c = cos(rad);
	float s = sin(rad);
	mat(1, 1) = c;
	mat(1, 2) = -s;
	mat(2, 1) = s;
	mat(2, 2) = c;
	neo = mat * neo;
	neoInv = neo.inverse();
}

void Entity::rotateY(const float deg) {
    Matrix mat;
    float rad = deg * M_PI / 180;
    float c = cos(rad);
    float s = sin(rad);
    mat(0, 0) = c;
    mat(0, 2) = s;
    mat(2, 0) = -s;
    mat(2, 2) = c;
    neo = mat * neo;
    neoInv = neo.inverse();
}

void Entity::rotateZ(const float deg) {
    Matrix mat;
    float rad = deg * M_PI / 180;
    float c = cos(rad);
    float s = sin(rad);
    mat(0, 0) = c;
    mat(0, 1) = -s;
    mat(1, 0) = s;
    mat(1, 1) = c;
    neo = mat * neo;
    neoInv = neo.inverse();
}

void Entity::rotate(const Vector deg) {
    rotateX(deg.X());
    rotateY(deg.Y());
    rotateZ(deg.Z());
}

Rayon Entity::localToGlobal(const Rayon& ray) const {
    Point origin = localToGlobal(ray.Origin());
    Vector direction = localToGlobal(ray.Dir());
    return Rayon(origin, direction);
}

Rayon Entity::globalToLocal(const Rayon& ray) const {
    Point origin = globalToLocal(ray.Origin());
    Vector direction = globalToLocal(ray.Dir());
    return Rayon(origin, direction);
}

Point Entity::localToGlobal(const Point& pts) const {
    return neo * pts;
}

Vector Entity::localToGlobal(const Vector& vec) const {
    return neo * vec;
}

Point Entity::globalToLocal(const Point& pts) const {
    return neoInv * pts;
}

Vector Entity::globalToLocal(const Vector& vec) const {
    return neoInv * vec;
}

Matrix Entity::getMatrix() const {
    return neo;
}

Vector Entity::position()const {
    return Vector(neo(0, 3), neo(1, 3), neo(2, 3));
}

std::ostream& operator<<(std::ostream& os, const Entity& ent) {
    return os << "Trans mat : " << ent.getMatrix() << std::endl;
}
#include "Light.h"

Color Light::id() const {
	return _id;
}

Color Light::is() const {
	return _is;
}

Vector Light::getVectorToLight(const Point &pts) const {
	return Vector((position() - pts)).normalized();
}

Vector Light::getVectorFromLight(const Point &pts) const {
	return Vector(pts - position()).normalized();
}
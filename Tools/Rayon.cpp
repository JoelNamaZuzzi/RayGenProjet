#include "Rayon.h"

Point Rayon::Origin()const {
	return origin;
}

void Rayon::Origin(Point pts) {
	origin = pts;
}

Vector Rayon::Dir() const {
	return dir;
}

void Rayon::Dir(Vector di) {
	dir = di;
}

Rayon Rayon::normalized() {
	return Rayon(origin, dir.normalized());
}

std::ostream &operator<<(std::ostream &os, const Rayon &ray) {
	return os << "(" << "Origin : " << ray.Origin() << " dir : " << ray.Dir() << std::endl;
}
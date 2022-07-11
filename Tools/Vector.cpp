#include "Vector.h"
#include <cmath>

float Vector::norm()const {
	return sqrt(pow(this->mx, 2) + pow(this->my, 2) + pow(this->mz, 2));
}

Vector Vector::normalized() const {
	float val = this->norm();
	return { this->mx / val, this->my / val, this->mz / val };
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
	return os << "(" << v.X() << ", " << v.Y() << ", " << v.Z() << ") ";
}
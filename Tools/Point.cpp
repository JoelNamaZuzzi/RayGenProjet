#include "Point.h"

float Point::dot(const Point& p) const {
	return this->mx * p.mx + this->my * p.my + this->mz * p.mz;
}

float Point::operator[](const int i) const {
    if (i == 0)
        return mx;

    if (i == 1)
        return my;

    if (i == 2)
        return mz;
}

float& Point::operator[](const int i) {
    if (i == 0)
        return mx;

    if (i == 1)
        return my;

    if (i == 2)
        return mz;
}

Point Point::operator+(const Point& p) const {
    return { this->mx + p.mx, this->my + p.my, this->mz + p.mz };
}

Point Point::operator*(const Point& p) const {
    return { this->mx * p.mx, this->my * p.my, this->mz * p.mz };
}

Point Point::operator-(const Point& p) const {
    return (*this) + (-p);
}

Point Point::operator-() const {
    return { -this->mx, -this->my, -this->mz };
}

Point Point::operator*(const float factor) const {
    return { this->mx * factor, this->my * factor, this->mz * factor };
}

Point Point::operator/(float divide) const {
    return { this->mx / divide, this->my / divide, this->mz / divide };
}


std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.X() << ", " << p.Y() << ", " << p.Z() << ")";
}
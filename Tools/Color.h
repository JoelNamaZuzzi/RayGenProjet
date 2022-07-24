#pragma once
#ifndef RAYGEN_COLOR_H
#define RAYGEN_COLOR_H
#include <algorithm>
#include <iostream>
#include "Point.h"

class Color {
private: 
	float r;
	float g;
	float b;
public: 
	Color() = default;
	Color(const Color &col) = default;
	Color(const Point &pts) {
		this->r = std::clamp(pts[0], 0.f, 1.0f);
		this->g = std::clamp(pts[1], 0.0f, 1.0f);
		this->b = std::clamp(pts[2], 0.0f, 1.0f);
	}

	Color(const float &var) : r(var), g(var), b(var) {};

	Color(float red, float green, float blue) {
		this->r = std::clamp(red, 0.f, 1.0f);
		this->g = std::clamp(green, 0.0f, 1.0f);
		this->b = std::clamp(blue, 0.0f, 1.0f);
	}

	~Color() = default;

	float operator[](int i) const;

	float &operator[](int i);

	Color operator*(Color c) const;

	Color operator+(Color c) const;

	Color operator*(float factor) const;

	Color &operator+=(Color c);

	Color &operator/=(float f);

	void addNoClamp(Color col);

	void clear();

	void A(float val) const {

	}

	float A() const {
		return 1.f;
	}
};
#endif //RAYGEN_COLOR_H

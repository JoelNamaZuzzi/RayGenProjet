#pragma once
#ifndef RAYGEN_MATRIX_H
#define RAYGEN_MATRIX_H
#include <array>
#include "Point.h"
#include "Vector.h"

class Matrix {
private:
	std::array<float, 16> mat = {};
public:
	Matrix() {
		mat = Matrix::identity();
	};
	Matrix(const Matrix &m) {
		mat = m.mat;
	};

	~Matrix() = default;
	Matrix(std::array<float, 16> tab) {
		mat = tab;
	};


	std::array<float, 16> getMatrix() const;
	static std::array<float, 16> identity();
	Matrix inverse() const;
	float operator()(const int& i, const int& j) const;
	float& operator()(int i, int j);
	Matrix operator*(const Matrix &mult) const;
	Point operator*(const Point &p) const;
	Vector operator*(const Vector &p) const;
	Matrix operator*(const float &f) const;
};
std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
#endif RAYGEN_MATRIX_H

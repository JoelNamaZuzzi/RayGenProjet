#include <iostream>
#include "Matrix.h"

std::array<float, 16>Matrix::getMatrix() const{
	return mat;
}

std::array<float, 16>Matrix::identity() {
	std::array<float, 4 * 4> arr{};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				arr[i * 4 + j] = 1;
			}
			else {
				arr[i * 4 + j]=0;
			}
		}
	}
	return arr;
}

float Matrix::operator()(const int &i, const int &j) const {
	return mat[i * 4 + j];
}

float &Matrix::operator()(const int i, const int j) {
	return mat[i * 4 + j];
}

Matrix Matrix::operator*(const Matrix& var) const{
	const Matrix& othermat = (*this);
	Matrix res;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res(i, j) = othermat(i, 0) * var(0, j) + othermat(i, 1) * var(1, j) + othermat(i, 2) * var(2, j) + othermat(i, 3) * var(3, j);
		}
	}
	return res;
}

Matrix Matrix::operator*(const float& var) const{
	std::array<float, 16> res{};
	for (int i = 0; i < 4; i++) {
		res[i] = mat[i] * var;
	}
	return Matrix(res);
}

Point Matrix::operator*(const Point &pts) const {
	Point res;
	for (int i = 0; i < 3; i++) {
		res[i]= (*this)(i, 0) * pts[0] + (*this)(i, 1) * pts[1] + (*this)(i, 2) * pts[2] + (*this)(i, 3);
	}
	return res;
}

Vector Matrix::operator*(const Vector& vec) const {
	Vector res;
	for (int i = 0; i < 3; ++i) {
		res[i] = (*this)(i, 0) * vec[0] + (*this)(i, 1) * vec[1] + (*this)(i, 2) * vec[2];
	}
	return res;
}

Matrix Matrix::inverse() const {
    std::array<float, 16> mattmp{}, matinv{};
    float det;
    int i;

    mattmp[0] = mat[5] * mat[10] * mat[15] - mat[5] * mat[11] * mat[14] -mat[9] * mat[6] * mat[15] +mat[9] * mat[7] * mat[14] +mat[13] * mat[6] * mat[11] -mat[13] * mat[7] * mat[10];

    mattmp[4] = -mat[4] * mat[10] * mat[15] +mat[4] * mat[11] * mat[14] +mat[8] * mat[6] * mat[15] - mat[8] * mat[7] * mat[14] - mat[12] * mat[6] * mat[11] +mat[12] * mat[7] * mat[10];

    mattmp[8] = mat[4] * mat[9] * mat[15] -mat[4] * mat[11] * mat[13] - mat[8] * mat[5] * mat[15] + mat[8] * mat[7] * mat[13] +mat[12] * mat[5] * mat[11] - mat[12] * mat[7] * mat[9];

    mattmp[12] = -mat[4] * mat[9] * mat[14] +mat[4] * mat[10] * mat[13] +mat[8] * mat[5] * mat[14] -mat[8] * mat[6] * mat[13] -mat[12] * mat[5] * mat[10] +mat[12] * mat[6] * mat[9];

    mattmp[1] = -mat[1] * mat[10] * mat[15] +mat[1] * mat[11] * mat[14] +mat[9] * mat[2] * mat[15] - mat[9] * mat[3] * mat[14] -mat[13] * mat[2] * mat[11] +mat[13] * mat[3] * mat[10];

    mattmp[5] = mat[0] * mat[10] * mat[15] - mat[0] * mat[11] * mat[14] -mat[8] * mat[2] * mat[15] +  mat[8] * mat[3] * mat[14] + mat[12] * mat[2] * mat[11] - mat[12] * mat[3] * mat[10];

    mattmp[9] = -mat[0] * mat[9] * mat[15] +mat[0] * mat[11] * mat[13] +mat[8] * mat[1] * mat[15] -mat[8] * mat[3] * mat[13] -mat[12] * mat[1] * mat[11] + mat[12] * mat[3] * mat[9];

    mattmp[13] = mat[0] * mat[9] * mat[14] -mat[0] * mat[10] * mat[13] -mat[8] * mat[1] * mat[14] + mat[8] * mat[2] * mat[13] +mat[12] * mat[1] * mat[10] -mat[12] * mat[2] * mat[9];

    mattmp[2] = mat[1] * mat[6] * mat[15] - mat[1] * mat[7] * mat[14] -mat[5] * mat[2] * mat[15] +mat[5] * mat[3] * mat[14] +mat[13] * mat[2] * mat[7] -mat[13] * mat[3] * mat[6];

    mattmp[6] = -mat[0] * mat[6] * mat[15] +mat[0] * mat[7] * mat[14] +mat[4] * mat[2] * mat[15] -mat[4] * mat[3] * mat[14] -mat[12] * mat[2] * mat[7] +mat[12] * mat[3] * mat[6];

    mattmp[10] = mat[0] * mat[5] * mat[15] -mat[0] * mat[7] * mat[13] -mat[4] * mat[1] * mat[15] +mat[4] * mat[3] * mat[13] +mat[12] * mat[1] * mat[7] -mat[12] * mat[3] * mat[5];

    mattmp[14] = -mat[0] * mat[5] * mat[14] +mat[0] * mat[6] * mat[13] +mat[4] * mat[1] * mat[14] - mat[4] * mat[2] * mat[13] -mat[12] * mat[1] * mat[6] +mat[12] * mat[2] * mat[5];

    mattmp[3] = -mat[1] * mat[6] * mat[11] +mat[1] * mat[7] * mat[10] +mat[5] * mat[2] * mat[11] -mat[5] * mat[3] * mat[10] -mat[9] * mat[2] * mat[7] +mat[9] * mat[3] * mat[6];

    mattmp[7] = mat[0] * mat[6] * mat[11] -mat[0] * mat[7] * mat[10] - mat[4] * mat[2] * mat[11] +mat[4] * mat[3] * mat[10] +mat[8] * mat[2] * mat[7] -mat[8] * mat[3] * mat[6];

    mattmp[11] = -mat[0] * mat[5] * mat[11] +mat[0] * mat[7] * mat[9] + mat[4] * mat[1] * mat[11] -mat[4] * mat[3] * mat[9] -mat[8] * mat[1] * mat[7] + mat[8] * mat[3] * mat[5];

    mattmp[15] = mat[0] * mat[5] * mat[10] -mat[0] * mat[6] * mat[9] - mat[4] * mat[1] * mat[10] + mat[4] * mat[2] * mat[9] + mat[8] * mat[1] * mat[6] -mat[8] * mat[2] * mat[5];

    det = mat[0] * mattmp[0] + mat[1] * mattmp[4] + mat[2] * mattmp[8] + mat[3] * mattmp[12];
    det = 1.0 / det;

    for (i = 0; i < 16; i++)
        matinv[i] = matinv[i] * det;

    return Matrix(matinv);
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
	std::array<float, 16> arr = matrix.getMatrix();
	for (int i = 0; i < arr.size(); i++) {
		if (i % 4 == 0) {
			os << std::endl;
		}
		os << " " << arr[i] << " ";
	}

	return os << std::endl;
}
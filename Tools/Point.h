#pragma once

#ifndef RAYGEN_POINT_H
#define RAYGEN_POINT_H

#include <iostream>

class Point {
protected:
	float mx;
	float my;
	float mz;

public:
	Point() :mx(0), my(0), mz(0) {};
	Point(float x, float y, float z) : mx(x), my(y), mz(z) {};
	Point(const Point& p) : mx(p.mx), my(p.my), mz(p.mz) {};

    float dot(const Point& p) const;

    float operator[](int i) const;

    float& operator[](int i);

    Point operator+(const Point &p) const;

    Point operator-(const Point &p) const;

    Point operator*(const Point &p) const;

    Point operator-() const;

    Point operator*(float factor) const;

    Point operator/(float divide) const;

    float X() const {
        return mx;
    }

    void X(float val) {
        mx = val;
    }

    float Y() const {
        return my;
    }

    void Y(float val) {
        my = val;
    }

    float Z() const {
        return mz;
    }

    void Z(float val) {
        mz = val;
    }
};

std::ostream &operator<<(std::ostream &os, const Point &p);

#endif RAYGEN_POINT_H
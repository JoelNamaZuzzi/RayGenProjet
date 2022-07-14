#include "Color.h"

Color Color::operator*(const Color col) const {
    return Color(r * col.r, g * col.g, b * col.b);
}

Color Color::operator+(Color col) const {
    return Color(r + col.r, g + col.g, b + col.b);
}

float Color::operator[](const int i) const {
    if (i == 0)
        return this->r;

    if (i == 1)
        return this->g;

    if (i == 2)
        return this->b;
}

float& Color::operator[](int i) {
    if (i == 0)
        return this->r;

    if (i == 1)
        return this->g;

    if (i == 2)
        return this->b;
}

Color Color::operator*(float val) const {
    return Color(r * val, g * val, b * val);
}

Color& Color::operator+=(Color col) {
    this->r = std::clamp(r + col[0], 0.f, 1.0f);
    this->g = std::clamp(g + col[1], 0.0f, 1.0f);
    this->b = std::clamp(b + col[2], 0.0f, 1.0f);
    return *this;
}

void Color::addNoClamp(Color col) {
    this->r += col[0];
    this->g += col[1];
    this->b += col[2];
}

Color& Color::operator/=(float var) {
    this->r = std::clamp(r / var, 0.f, 1.0f);
    this->g = std::clamp(g / var, 0.0f, 1.0f);
    this->b = std::clamp(b / var, 0.0f, 1.0f);
    return *this;
}

void Color::clear() {
    r = 0.f;
    g = 0.f;
    b = 0.f;
}
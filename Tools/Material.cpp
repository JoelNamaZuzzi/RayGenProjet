#include "Material.h"

void Material::Shininess(const float val) {
	shininess = val;
}

float Material::Shininess() const {
	return shininess;
}

void Material::Amb(const Color col) {
	amb = col;
}

Color Material::Amb() const{
	return amb;
}

void Material::Dif(const Color col) {
	dif = col;
}

Color Material::Dif() const {
	return dif;
}

void Material::Spec(const Color col) {
	spec = col;
}

Color Material::Spec() const {
	return spec;
}

bool Material::Textured() const {
	return texture != nullptr;
}

std::shared_ptr<Image> Material::getTexture() const {
	return texture;
}

Color Material::getTexture(const Point &pts) const {
	return (*texture)(1 - pts[1], 1 - pts[0]);
}
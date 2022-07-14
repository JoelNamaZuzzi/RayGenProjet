#pragma once
#ifndef RAYGEN_MATERIAL_H
#define RAYGEN_MATERIAL_H

#include "Color.h"
#include "Rayon.h"
#include "Point.h"
#include "../Image/Image.h"

class Material {
private:
	Color amb;
	Color dif;
	Color spec;
	std::shared_ptr<Image> texture;
	float shininess;
public:
	Material() = default;
	Material(Color a, Color d, Color sp, float sh) : amb(a), dif(d), spec(sp), shininess(sh) {}
	Material (std::shared_ptr<Image> tex, Color a, Color d, Color sp, float sh): texture(tex), amb(a), dif(d), spec(sp), shininess(sh){}
	~Material() = default;

	void Shininess(const float sp);
	float Shininess() const;
	void Amb(const Color col);
	void Dif(const Color col);
	void Spec(const Color col);
	Color Amb() const;
	Color Dif() const;
	Color Spec() const;
	bool Textured() const;
	std::shared_ptr<Image> getTexture() const;
	Color getTexture(const Point &pts) const;
};

#endif //RAYGEN_MATERIAL_H
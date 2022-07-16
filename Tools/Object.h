#pragma once
#ifndef RAYGEN_OBJ_H
#define RAYGEN_OBJ_H
#include <string>
#include <utility>
#include <vector>
#include "../Entity.h"
#include "../Point.h"
#include "../Material.h"
#include "../Rayon.h"

class Object : public Entity {
private: 
	std::string name;
	std::vector<Material> mats;
	int nbImpact;
public: 
	Object() = default;
	Object(Vector trans, Vector rot, Vector sca, std::string n, std::vector<Material>m): name(std::move(n)), mats(std::move(m)), Entity(trans, rot, sca){}
	Object(Vector trans, Vector rot, Vector sca, std::vector<Material> m): mats(std::move(m)), Entity(trans,rot,sca){}
	~Object() = default;

	virtual Point getTextureCoordinates(const Point &pts) const = 0;
	virtual Rayon getNormal(const Point &pts, const Point &org) const = 0;
	virtual bool intersect(const Rayon &ray, Point &pts) const = 0;
	Material getMaterial(const Point &p) const;
	bool textured(int id) const;
	int nbMat() const;
	void mat(Material m);
	std::string getName() const;
};


#endif //RAYGEN_OBJ_H

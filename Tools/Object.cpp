#include "Object.h"

bool Object::textured(int id) const {
	return mats[id].Textured();
}

int Object::nbMat() const {
	return mats.size();
}

void Object::mat(Material mat) {
	mats.push_back(mat);
}

std::string Object::getName() const {
	return name;
}

Material Object::getMaterial(const Point &pts) const {
	Point lp = globalToLocal(pts);
	if (mats.size() > 1) {
		if ((int(lp.X() * 10)) % 2 == 0) {
			return mats[0];
		}
		else {
			return mats[1];
		}
	}
	return mats[0];
}
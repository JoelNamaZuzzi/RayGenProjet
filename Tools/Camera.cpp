#include "Camera.h"

Rayon Camera::getRay(const float x, const float y) {
    Rayon r(x, y, 0, 0, 0, 0);
    Point foc(0, 0, focal);
    r.Dir(r.Origin() - foc);
    r = localToGlobal(r);
    return r.normalized();
}

void Camera::screenshot(const std::string &name, const int &height, const bool &displayShadows, const int &ssaa) {
    Image im(height, height, scene.getBackground());
    //std::cout << "test";
#pragma omp parallel for
    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < height; ++y) {

            Color pix(0.f);

            for (int subX = 0; subX < ssaa; ++subX) {
                for (int subY = 0; subY < ssaa; ++subY) {
                    float viewportX = ((x + ((float)subX / (float)ssaa)) / ((float)height - 1) * 2) - 1;
                    float viewportY = ((height - y + ((float)subY / (float)ssaa)) / ((float)height - 1) * 2) - 1;
                    Rayon r = getRay(viewportX, viewportY);
                    Point impact;
                    Point nearestImpact;
                    int counter=0;
                    Object* nearestObj = nullptr;
                    for (Object* o : scene.getObjects()) {
                        //std::cout << "obj" << std::endl;
                        if (o->intersect(r, impact)) {
                            std::cout << "impact" << std::endl;
                            if (!nearestObj || this->CloserThan(nearestImpact, impact, this->position())) {
                                nearestObj = o;
                                nearestImpact = impact;
                                std::cout << "nearestobj" << std::endl;
                            }
                        }
                    }
                    if (nearestObj) {
                        pix.addNoClamp(getImpactColor(r, nearestObj, nearestImpact, displayShadows));
                        std::cout << getImpactColor(r, nearestObj, nearestImpact, displayShadows)[0] << getImpactColor(r, nearestObj, nearestImpact, displayShadows)[1] << getImpactColor(r, nearestObj, nearestImpact, displayShadows)[2] << std::endl;
                    }
                }
            }
            im(y, x, pix /= (float)(ssaa * ssaa));
            pix.clear();

        }
    }
    std::cout << "img made" << std::endl;
    im.write(name + ".jpg");
}

bool Camera::CloserThan(const Point &oldImpact, const Point &newImpact, const Vector &comparison) const {
    float oldDistance = Vector(oldImpact - comparison).norm();
    float newDistance = Vector(newImpact - comparison).norm();
    return newDistance < oldDistance;
}

Color Camera::getImpactColor(const Rayon &ray, Object *obj, const Point &impact, const bool &displayShadows) {

    Material m = obj->getMaterial(impact);
    Rayon normal = obj->getNormal(impact, ray.Origin());
    Color c = m.Amb() * scene.getAmbiant();
    bool shadowDetected = false;

    for (int l = 0; l < scene.nbLights(); l++) {
        const Light* light = scene.getLight(l);
        Vector lv = light->getVectorToLight(impact);
        if (displayShadows) {
            Rayon shadowRay(impact, lv);
            Point impactShadow;
            for (Object* o : scene.getObjects()) {
                if (o != obj
                    && obj->getName() != "skybox" &&
                    o->intersect(shadowRay, impactShadow) && lv.dot(normal.Dir()) > 0) {
                    if (this->CloserThan(light->position(), impactShadow, impact)) {
                        shadowDetected = true;
                    }

                }
            }
        }
        if (!shadowDetected) {
            float alpha = lv.dot(normal.Dir());
            if (alpha > 0)
                c += light->id() * m.Dif() * alpha;

            Vector rm = (normal.Dir() * (lv.dot(normal.Dir() * 2))) - lv;
            float beta = -rm.dot(ray.Dir());
            if (beta > 0)
                c += light->is() * m.Spec() * pow(beta, m.Shininess());
        }
        shadowDetected = false;

    }
    if (m.Textured()) {
        Point texCoordinate = obj->getTextureCoordinates(impact);
        Color texColor = m.getTexture(texCoordinate);
        c = c * texColor;
    }


    return c;
}
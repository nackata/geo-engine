#pragma once

#include <vector>
#include "staticobject.h"
#include "dynamicnoninter.h"
#include "dynamicinter.h"
#include "light.h"
#include "fpsCam.h"

#define POINT_LIGHTS 16

class Scene
{
    std::vector<StaticObject *> staticObj;
    std::vector<DynamicNonInter *> dynNonInterObj;
    std::vector<DynamicInter *> dynInterObj;
    std::vector<Light*> phongLights;

    FpsCam * camera;

    bool finish = false;

public:

    std::vector<StaticObject *> & staticObjects() { return staticObj; }
    std::vector<DynamicNonInter *> & dynamicNonInterObjects() { return dynNonInterObj; }
    std::vector<DynamicInter *> & dynamicInterObjects() { return dynInterObj; }
    std::vector<Light*> & lights() { return phongLights; }

    void updateScene(double delta);

    DynamicObject * search(std::string ID);

    void addObj(StaticObject * obj) { staticObj.push_back(obj); }
    void addObj(DynamicNonInter * obj) { dynNonInterObj.push_back(obj); }
    void addObj(DynamicInter * obj) { dynInterObj.push_back(obj); }

    bool finished() { return finish; }

    void addLight(Light * l) {
        if (phongLights.size() >= POINT_LIGHTS)
        {
            std::cerr << "too many lights" << std::endl;
            return;
        }
        phongLights.push_back(l);
    }

    void setCam(FpsCam * cam) { this->camera = cam; }

    Scene() {}
    ~Scene() {
        for (auto p : staticObj)
        {
            delete p;
        }
        for (auto p : dynNonInterObj)
        {
            delete p;
        }
        for (auto p : dynInterObj)
        {
            delete p;
        }
        for (auto p : phongLights)
        {
            delete p;
        }
    }
};




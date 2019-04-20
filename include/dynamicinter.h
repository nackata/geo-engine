#pragma once

#include "dynamicobject.h"
#include "fpsCam.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class DynamicInter : public DynamicObject
{
    int actionRadius;
    bool intersectSegmentTriangle(glm::vec3 p, glm::vec3 q, glm::vec3 a, glm::vec3 b, glm::vec3 c);
public:
    DynamicInter(std::string & modelPath, std::string &ID, int rad = 1) : DynamicObject(modelPath, ID) { actionRadius = rad; }

    virtual void update(double deltaTime, FpsCam & cam) = 0;

    bool checkIsTriggered(FpsCam & cam);

protected:
    int timer = 0;
};




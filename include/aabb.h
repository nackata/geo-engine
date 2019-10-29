#pragma once

#include "lib/glm/glm.hpp"

class AABB
{
    glm::vec3 center{0.0, 0.0, 0.0};

    glm::vec3 Len{1.0, 1.0, 1.0};

public:
    AABB(glm::vec3 pos, float x, float y, float z) { center = pos;
                                                                 Len.x = x;
                                                                 Len.y = y;
                                                                 Len.z = z; }

    AABB() {}

    glm::vec3 getCenter() { return center; }
    glm::vec3 getLen() { return Len; }

    void setPos(glm::vec3 pos) { center = pos; }
    void setPos(float x, float y, float z) { center = glm::vec3(x, y, z); }
    void setLen(glm::vec3 toSet) { Len = toSet; }
};




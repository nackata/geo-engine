#pragma once

#include "aabb.h"
#include "glm/glm.hpp"

#include <array>

class TestAlgo
{
public:
    static bool aabbTriangleTest(AABB & box, std::array<glm::vec3, 3> const& triangle);
};



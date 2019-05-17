#pragma once

#include "aabb.h"
#include "aabbtritest.h"
#include "glm/glm.hpp"

#include <array>

class TestAlgo
{
public:
    virtual bool aabbTriangleTest(AABB & box, std::array<glm::vec3, 3> const& triangle) = 0;
};


class TestAdapter : public TestAlgo, public AabbTriTest
{
public:
    bool aabbTriangleTest(AABB &box, const std::array<glm::vec3, 3> &triangle);
};

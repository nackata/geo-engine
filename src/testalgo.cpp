#include "../include/testalgo.h"

bool TestAdapter::aabbTriangleTest(AABB &box, const std::array<glm::vec3, 3> &triangle)
{
    float center[3];
    center[0] = box.getCenter().x;
    center[1] = box.getCenter().y;
    center[2] = box.getCenter().z;

    float halfLen[3];
    glm::vec3 len = box.getLen();
    halfLen[0] = len.x;
    halfLen[1] = len.y;
    halfLen[2] = len.z;

    float trivert[3][3];

    trivert[0][0] = triangle.at(0).x;
    trivert[0][1] = triangle.at(0).y;
    trivert[0][2] = triangle.at(0).z;

    trivert[1][0] = triangle.at(1).x;
    trivert[1][1] = triangle.at(1).y;
    trivert[1][2] = triangle.at(1).z;

    trivert[2][0] = triangle.at(2).x;
    trivert[2][1] = triangle.at(2).y;
    trivert[2][2] = triangle.at(2).z;

    return triBoxOverlap(center, halfLen, trivert);
}

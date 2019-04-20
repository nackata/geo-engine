#include "../include/sceneobject.h"

int triBoxOverlap(float boxcenter[3],float boxhalfsize[3],float triverts[3][3]);

#include <iostream>

Object::Object(std::string modelPath) : model(modelPath.c_str())
{
    this->modelPath = modelPath;
}

bool inter(AABB &a, glm::vec3 vert0, glm::vec3 vert1, glm::vec3 vert2)
{
    float center[3];
    center[0] = a.getCenter().x;
    center[1] = a.getCenter().y;
    center[2] = a.getCenter().z;

    float halfLen[3];
    glm::vec3 len = a.getLen();
    halfLen[0] = len.x;
    halfLen[1] = len.y;
    halfLen[2] = len.z;

    float trivert[3][3];

    trivert[0][0] = vert0.x;
    trivert[0][1] = vert0.y;
    trivert[0][2] = vert0.z;

    trivert[1][0] = vert1.x;
    trivert[1][1] = vert1.y;
    trivert[1][2] = vert1.z;

    trivert[2][0] = vert2.x;
    trivert[2][1] = vert2.y;
    trivert[2][2] = vert2.z;

    return triBoxOverlap(center, halfLen, trivert);
}

bool Object::aabbIntersects(AABB & a)
{
    if (glm::length(model.getPosition() - (a.getCenter() + a.getLen().x)) > model.getBoundSphere() &&
        glm::length(model.getPosition() - (a.getCenter() + a.getLen().x)) > model.getBoundSphere() &&
        glm::length(model.getPosition() - (a.getCenter() + -a.getLen().z)) > model.getBoundSphere() &&
        glm::length(model.getPosition() - (a.getCenter() + -a.getLen().z)) > model.getBoundSphere()) return false;

    std::vector<Mesh> meshes = model.getMeshes();
    glm::mat4 modelMat = model.getModel();

    for(Mesh & m: meshes)
    {
        std::vector<Vertex> vertices = m.getVertices();
        std::vector<unsigned int> indices = m.getIndices();

        for (unsigned int i = 0; i < indices.size(); i += 3)
        {
            glm::vec3 vert0 = glm::vec3(modelMat * glm::vec4(vertices[indices[i]].Position, 1.0));
            glm::vec3 vert1 = glm::vec3(modelMat * glm::vec4(vertices[indices[i + 1]].Position, 1.0));
            glm::vec3 vert2 = glm::vec3(modelMat * glm::vec4(vertices[indices[i + 2]].Position, 1.0));

            if (inter(a, vert0, vert1, vert2))  return true;
        }
    }

    return false;
}


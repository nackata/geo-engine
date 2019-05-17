#include "../include/sceneobject.h"

#include <iostream>

Object::Object(std::string modelPath) : model(modelPath.c_str())
{
    this->modelPath = modelPath;
}

bool Object::aabbIntersects(AABB & a)
{
    if (glm::length(model.getPosition() - (a.getCenter() + a.getLen().x)) > model.getBoundSphere() &&
        glm::length(model.getPosition() - (a.getCenter() + a.getLen().x)) > model.getBoundSphere() &&
        glm::length(model.getPosition() - (a.getCenter() + -a.getLen().z)) > model.getBoundSphere() &&
        glm::length(model.getPosition() - (a.getCenter() + -a.getLen().z)) > model.getBoundSphere()) return false;

    std::vector<Mesh> meshes = model.getMeshes();
    glm::mat4 modelMat = model.getModel();

    TestAlgo * test = new TestAdapter();

    for(Mesh & m: meshes)
    {
        std::vector<Vertex> vertices = m.getVertices();
        std::vector<unsigned int> indices = m.getIndices();

        for (unsigned int i = 0; i < indices.size(); i += 3)
        {
            std::array<glm::vec3, 3> triangle;

            triangle.at(0) = glm::vec3(modelMat * glm::vec4(vertices[indices[i]].Position, 1.0));
            triangle.at(1) = glm::vec3(modelMat * glm::vec4(vertices[indices[i + 1]].Position, 1.0));
            triangle.at(2) = glm::vec3(modelMat * glm::vec4(vertices[indices[i + 2]].Position, 1.0));

            if (test->aabbTriangleTest(a, triangle))  return true;
        }
    }

    return false;
}


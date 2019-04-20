#include "../include/dynamicinter.h"

#include <iostream>

int intersect_triangle(glm::vec3 orig, glm::vec3 dir,
                       glm::vec3 vert0, glm::vec3 vert1, glm::vec3 vert2);

bool DynamicInter::checkIsTriggered(FpsCam &cam)
{
    if (glm::length(model.getPosition() - cam.getPos()) > actionRadius) return false;

    glm::mat4 modelMat = model.getModel();

    std::vector<Mesh> meshes = model.getMeshes();

    bool intersect = false;
    for (Mesh & m : meshes)
    {
        std::vector<unsigned int> indices = m.getIndices();
        std::vector<Vertex> vertices = m.getVertices();

        for (unsigned int i = 0; i < indices.size(); i += 3)
        {
            glm::vec3 vert0 = glm::vec3(modelMat * glm::vec4(vertices[indices[i]].Position, 1.0));
            glm::vec3 vert1 = glm::vec3(modelMat * glm::vec4(vertices[indices[i + 1]].Position, 1.0));
            glm::vec3 vert2 = glm::vec3(modelMat * glm::vec4(vertices[indices[i + 2]].Position, 1.0));

            if (intersect_triangle(cam.getPos(), cam.getDir(),vert0, vert1, vert2))
                intersect = true;
        }
    }

    return intersect;
}

#define EPSILON 0.000001


int intersect_triangle(glm::vec3 orig, glm::vec3 dir,
               glm::vec3 vert0, glm::vec3 vert1, glm::vec3 vert2)
{
   glm::vec3 edge1, edge2, tvec, pvec, qvec;
   double det,inv_det;

   /* find vectors for two edges sharing vert0 */
   edge1 = vert1 - vert0;
   edge2 = vert2 - vert0;

   /* begin calculating determinant - also used to calculate U parameter */
   pvec = glm::cross(dir, edge2);

   /* if determinant is near zero, ray lies in plane of triangle */
   det = glm::dot(edge1, pvec);

   if (det > -EPSILON && det < EPSILON)
     return 0;
   inv_det = 1.0 / det;

   /* calculate distance from vert0 to ray origin */
   tvec = orig - vert0;

   /* calculate U parameter and test bounds */
   double u = glm::dot(tvec, pvec) * inv_det;
   if (u < 0.0 || u > 1.0)
     return 0;

   /* prepare to test V parameter */
   qvec = glm::cross(tvec, edge1);

   /* calculate V parameter and test bounds */
   double v = glm::dot(dir, qvec) * inv_det;
   if (v < 0.0 || u + v > 1.0)
     return 0;

   return 1;
}

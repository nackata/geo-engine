#pragma once

#define GL_GLEXT_PROTOTYPES
#include <GLFW/glfw3.h>

#include <vector>
#include <string>
#include <iostream>

#include "shader.h"
#include "mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#include "stb_image.h"

#include <iostream>

class Model 
{
    public:
        /*  Functions   */
        Model(const char *path)
        {
            loadModel(path);

            std::vector<Mesh> meshes = getMeshes();
            double rad = 0;

            for (Mesh & m: meshes)
            {
                std::vector<Vertex> vert = m.getVertices();
                for (Vertex & v: vert)
                {
                    double len = glm::length(getPosition() - (v.Position));
                    if (len > rad)  rad = len;
                }
            }

            boundSphereRad = rad;
        }

        void Draw(Shader shader);

        void setPosition(glm::vec3 position) {this->position = position; }
        void setPosition(float x, float y, float z) { this->position = glm::vec3(x, y, z); }

        glm::vec3 getPosition() { return position; }

        void setScale(glm::vec3 scale) {this->scale = scale; boundUpd();}
        void setScale(float x, float y, float z) { this->scale = glm::vec3(x, y, z); boundUpd();}



        void setRotation(glm::vec3 rotation, float angle) { this->rotation = glm::angleAxis(glm::radians(angle), rotation); }

        void setRotation(float x, float y, float z, float w) { this->rotation = glm::quat(x, y, z, w);}

        void setRotation(glm::quat quat) { this->rotation = quat;}

        void addRotation(glm::vec3 rotation, float angle) { glm::quat second = glm::angleAxis(angle, rotation);
                                                            this->rotation = second * this->rotation; }

        glm::mat4 getModel();

        glm::vec3 getScale() { return scale; }
        glm::quat getRotation() { return rotation; }

        std::vector<Mesh> & getMeshes() { return meshes; }

        double getBoundSphere() { return boundSphereRad; }

        void setDiffuseColor(glm::vec3 color);

    private:
        /*  Model Data  */
        std::vector<Mesh> meshes;
        std::string directory;

        double boundSphereRad = 0.0;

        std::vector<Texture> textures_loaded; 
        /*  Functions   */
        void loadModel(std::string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, 
            std::string typeName);

        glm::vec3 position{0.0, 0.0, 0.0};
        glm::vec3 scale{1.0, 1.0, 1.0};
        glm::quat rotation = glm::angleAxis(0.0f, glm::vec3(0.0, 0.0, 0.0));
        float angle = 0.0;

        void boundUpd() {
            double scaleVal = scale.x;
            if (scaleVal < scale.y) scaleVal = scale.y;
            if (scaleVal < scale.z) scaleVal = scale.z;

            boundSphereRad *= scaleVal;
        }
};

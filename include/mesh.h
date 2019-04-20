#pragma once
// Requires glfw3 for processing input

#define GL_GLEXT_PROTOTYPES
#include <GLFW/glfw3.h>


#include "shader.h"

#include <vector>
#include <string>

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    std::string type;
    std::string path;
    glm::vec3 diffuseColor;
}; 

class Mesh {
public:
    //  Functions 
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    void Draw(Shader shader);

    std::vector<Vertex> & getVertices() { return vertices; }
    std::vector<unsigned int> & getIndices() { return indices; }

    void setDiffuseColor(glm::vec3 color);
private:
    //   Mesh Data 
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;   
    //  Render data 
    unsigned int VAO, VBO, EBO;
    //  Functions  
    void setupMesh();
};

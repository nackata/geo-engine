#pragma once

#include <glad/glad.h>

#define GLFW_DLL
#define GL_GLEXT_PROTOTYPES
#include "GLFW/glfw3.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <lib/glm/glm.hpp>
#include <lib/glm/gtc/matrix_transform.hpp>

class Shader
{
public:
    unsigned int ID;
  
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    Shader() {}
    void use();


    void setBool(const std::string &name, bool value) const;
    void setInt  (const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec2(const std::string &name, const glm::vec2 &value) const;
    void setVec2(const std::string &name, float x, float y) const;   
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setVec4(const std::string &name, float x, float y, float z, float w) const;
    void setMat2(const std::string &name, const glm::mat2 &mat) const;
    void setMat3(const std::string &name, const glm::mat3 &mat) const;    
    void setMat4(const std::string &name, glm::mat4 & mat) const;
private:

    void checkCompileErrors(unsigned int shader, std::string type);
};

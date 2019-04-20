#pragma once

#include <iostream>
#include <map>
#include <string>

#define GL_GLEXT_PROTOTYPES
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "shader.h"

class ScreenText
{
    struct Character {
        GLuint textureID;
        glm::ivec2 size;
        glm::ivec2 bearing;
        GLuint advance;
    };

    Shader textShader;

    std::map<GLchar, Character> Characters;
    GLuint VAO, VBO;

    GLFWwindow * window;

public:
    void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);

    ScreenText() {}
    ScreenText(GLFWwindow * window);
};




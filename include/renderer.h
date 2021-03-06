#pragma once

#include <glad/glad.h>

#define GLFW_DLL
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>

#include "shader.h"
#include "light.h"
#include "sceneobject.h"
#include "fpsCam.h"

#include <vector>
#include <string>

#define POINT_LIGHTS 16

class Renderer
{
    std::vector<Light*> phongLights;
    std::vector<Object*> objects;

    Shader mainShader;

    GLFWwindow * window;

    FpsCam * cam;

    double delta;
    double lastFrame = 0.0;

    bool dirLight = true;
    glm::vec3 directionDirLight{0.32, -1.0, 0.12};
public:
    void setDirLight(bool dl) { dirLight = dl; }

    GLFWwindow * getWin() { return window; }

    Renderer() { this->cam = cam; }

    void setCam(FpsCam * cam) { this->cam = cam; }

    bool init(int width = 1800, int height = 900, std::string title = "geoRIDDLE");

    double getTime() { return glfwGetTime(); }
    double getDelta() { return delta; }

    bool shouldClose() { return glfwWindowShouldClose(window); }

    void addObj(Object * obj) { objects.push_back(obj); }

    void swapBuffer() { glfwSwapBuffers(window); }

    void addLight(Light * l) {
        if (phongLights.size() >= POINT_LIGHTS)
        {
            std::cerr << "too many lights" << std::endl;
            return;
        }
        phongLights.push_back(l);
    }

    void drawScene();

    ~Renderer() { glfwTerminate(); }
};

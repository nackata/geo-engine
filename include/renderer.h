#pragma once

#include <GLFW/glfw3.h>
#include "fpsCam.h"
#include "sceneobject.h"
#include "light.h"


#include <string>


class Renderer
{
public:
    virtual void setDirLight(bool dl) = 0;

    virtual GLFWwindow * getWin() = 0;

    virtual void setCam(FpsCam * cam) = 0;

    virtual bool init(int width = 1920, int height = 1080, std::string title = "geoRIDDLE") = 0;

    virtual double getTime() = 0;
    virtual double getDelta() = 0;

    virtual bool shouldClose() = 0;

    virtual void addObj(Object * obj) = 0;

    virtual void swapBuffer() = 0;

    virtual void addLight(Light * l) = 0;

    virtual void drawScene() = 0;
};

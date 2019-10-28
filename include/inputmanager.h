#pragma once


#include <glad/glad.h>
#define GLFW_DLL
#include "GLFW/glfw3.h"
#include "player.h"

class InputManager
{
    // input processing

    void processKeyboardInput(double delta);
    void processMouseInput();

    float lastX = 0;
    float lastY = 0;
    bool firstMouse = true;

    Player * player;
    GLFWwindow * window;


public:
    void setPlayer(Player * player) { this->player = player; }
    void setWin(GLFWwindow * wind) { this->window = wind; }

    void processInput(double delta) { processKeyboardInput(delta);
                                      processMouseInput();    }

    InputManager() {}
};




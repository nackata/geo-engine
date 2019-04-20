#include "../include/inputmanager.h"


void InputManager::processMouseInput()
{
    double x;
    double y;

    glfwGetCursorPos(window, &x, &y);

    if (firstMouse)
    {
        lastX = x;
        lastY = y;
        firstMouse = false;
    }

    double xoffset = x - lastX;
    double yoffset = y - lastY;

    lastX = x;
    lastY = y;

    player->processMouseMovement(xoffset, yoffset);
}

void InputManager::processKeyboardInput(double delta)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);


    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        player->processKeyBoardInput(FORWARD, delta);
    }

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        player->processKeyBoardInput(BACKWARD, delta);
    }

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        player->processKeyBoardInput(LEFT, delta);
    }

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        player->processKeyBoardInput(RIGHT, delta);
    }

    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        player->processKeyBoardInput(UP, delta);
    }

    if(glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
        player->processKeyBoardInput(DOWN, delta);
    }

    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        player->setAction(true);
    }
    else
    {
        player->setAction(false);
    }
}


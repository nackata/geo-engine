#include "../include/keyboardmanager.h"

void WasdManager::getAction(GLFWwindow * window, Player * player, double delta, bool withDeletion)
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

    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        player->setAction(true);
    }
    else
    {
        player->setAction(false);
    }


    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && withDeletion)
    {
        player->setDeletion(true);
    }
    else
    {
        player->setDeletion(false);
    }
}

void ArrowManager::getAction(GLFWwindow * window, Player * player, double delta, bool withDeletion)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);


    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        player->processKeyBoardInput(FORWARD, delta);
    }


    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        player->processKeyBoardInput(BACKWARD, delta);
    }

    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        player->processKeyBoardInput(LEFT, delta);
    }

    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        player->processKeyBoardInput(RIGHT, delta);
    }

    if(glfwGetKey(window, GLFW_KEY_END) == GLFW_PRESS)
    {
        player->setAction(true);
    }
    else
    {
        player->setAction(false);
    }


    if(glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS && withDeletion)
    {
        player->setDeletion(true);
    }
    else
    {
        player->setDeletion(false);
    }
}

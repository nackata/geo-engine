#include "../include/inputmanager.h"


void ProtectedInputManager::processMouseInput()
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

void ProtectedInputManager::processKeyboardInput(double delta, bool withDeletion)
{
    keyManager->getAction(window, player, delta, withDeletion);
}


bool InputManager::checkAutho(const std::string &name)
{
    if (name == "nockato" || name == "admin") return true;

    return false;
}

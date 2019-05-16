#pragma once

#include <GLFW/glfw3.h>
#include "player.h"

class KeyboardManager
{
public:
    virtual void getAction(GLFWwindow * window, Player * player, double delta, bool withDeletion) = 0;

};


class WasdManager : public KeyboardManager
{
public:
    void getAction(GLFWwindow * window, Player * player, double delta, bool withDeletion);
};


class ArrowManager : public KeyboardManager
{
public:
    void getAction(GLFWwindow * window, Player * player, double delta, bool withDeletion);
};

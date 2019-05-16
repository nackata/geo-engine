#pragma once

#include <GLFW/glfw3.h>
#include "player.h"
#include "keyboardmanager.h"

class BaseInputManager
{
public:
    virtual void setPlayer(Player * player) = 0;
    virtual void setWin(GLFWwindow * wind) = 0;
};



class ProtectedInputManager : public BaseInputManager
{
    float lastX = 0;
    float lastY = 0;
    bool firstMouse = true;

    Player * player;
    GLFWwindow * window;

    KeyboardManager * keyManager;

    // input processing

    void processKeyboardInput(double delta, bool withDeletion = false);
    void processMouseInput();

public:
    enum KeyBoardType
    {
        WASD,
        ARROW
    };

    void setKeyBoard(KeyBoardType type)
    {
        if (type == WASD)
            keyManager = new WasdManager();
        else
            keyManager = new ArrowManager();
    }

    void setPlayer(Player * player) { this->player = player; }
    void setWin(GLFWwindow * wind) { this->window = wind; }

    void processInput(double delta, bool withDeletion = false) { processKeyboardInput(delta, withDeletion);
                                                                 processMouseInput();    }

    ProtectedInputManager() { keyManager = new ArrowManager(); }
};



class InputManager : public BaseInputManager
{
public:

    void setPlayer(Player * player) { manager.setPlayer(player); }
    void setWin(GLFWwindow * wind) { manager.setWin(wind); }

    void processInput(double delta, std::string const& name) { manager.processInput(delta, checkAutho(name)); }

    InputManager() {}

private:

    bool checkAutho(std::string const& name);
    ProtectedInputManager manager;
};




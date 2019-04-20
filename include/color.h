#pragma once

#include <glm/glm.hpp>

enum colorType
{
    COLOR_WHITE,
    COLOR_BLUE,
    COLOR_RED,
    COLOR_BLACK,
    COLOR_YELLOW,
    COLOR_PURPLE,
    COLOR_GREEN
};

class Color
{

public:
    static glm::vec3 getColor(colorType type)
    {
        glm::vec3 color;

        switch(type)
        {
            case COLOR_BLACK:
                color = glm::vec3(0.1, 0.1, 0.1);
                break;
            case COLOR_RED:
                color = glm::vec3(1.0, 0.070, 0.070);
                break;
            case COLOR_GREEN:
                color = glm::vec3(0.0, 1.0, 0.0);
                break;
            case COLOR_BLUE:
                color = glm::vec3(0.0, 0.0, 1.0);
                break;
            case COLOR_WHITE:
                color = glm::vec3(1.0, 1.0, 1.0);
                break;
            case COLOR_YELLOW:
                color = glm::vec3(0.992, 0.933, 0.070);
                break;
            case COLOR_PURPLE:
                color = glm::vec3(0.627451, 0.12549, 0.941176);
                break;
            default:
                color = glm::vec3(0.0, 0.0, 0.0);
        }

        return color;
    }
};



#pragma once

#include "dynamicnoninter.h"
#include <lib/glm/glm.hpp>
#include "color.h"

class RotatingCube : public DynamicNonInter
{
    glm::vec3 axis;
    double velocity = 0; // degrees per second
public:
    enum state
    {
        STATE_BLACK,
        STATE_WHITE,
        STATE_BLUE,
        STATE_RED,
        STATE_GREEN,
        STATE_YELLOW,
        STATE_PURPLE
    };

    RotatingCube(std::string fileName, std::string ID, glm::vec3 ax = glm::vec3(0.0, 1.0, 0.0)) : DynamicNonInter(fileName, ID), axis(ax)
    {
//        model.setDiffuseColor(getRgbColor(currentState));
    }

    QJsonObject save();

    void setAxis(glm::vec3 axis) { this->axis = axis; }
    glm::vec3 getAxis() { return axis; }

    void setVelocity(double vel) { velocity = vel; }
    double veloc() { return velocity ; }

    void rotate(glm::vec3 ax, double ang) { model.addRotation(ax, glm::radians(ang));  }

    void rotate(float x, float y, float z, double ang) { model.addRotation(glm::vec3(x, y, z), glm::radians(ang));  }

    void update(double deltaTime);

    glm::vec3 getRgbColor(RotatingCube::state st);

    void setNeedState(state st){ needState = st; }
    void setCurrState(state st){ currentState = st;
                                 /*model.setDiffuseColor(getRgbColor(currentState));*/ }
protected:
    state needState = STATE_BLACK;
    state currentState = STATE_WHITE;
};




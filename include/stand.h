#pragma once

#include "dynamicnoninter.h"

#include <glm/glm.hpp>

class Stand;

class StandState
{
public:

    virtual void update(double deltaTime, Stand & stand) = 0;
};

class MovingState : public StandState
{
public:

    void update(double deltaTime, Stand & stand);
};

class StandingState : public StandState
{
public:

    void update(double deltaTime, Stand & stand);
};



class Stand : public DynamicNonInter
{
    double velocity = 0;

    glm::vec3 newPos;
    glm::vec3 oldPos;
    double distance;
    glm::vec3 direction;

    float path = 0.0;

    StandState * current;

    void setState(StandState * state)
    {
        delete current;
        current = state;
    }

    friend class MovingState;
    friend class StandingState;

public:
    Stand(std::string fileName, std::string ID) : DynamicNonInter(fileName, ID)
    {
        current = new StandingState();
    }

    void setVelocity(double vel) { velocity = vel; }
    double veloc() { return velocity; }

    void translate(glm::vec3 newPosition) {
        oldPos = model.getPosition();
        newPos = newPosition;
        direction = newPos - oldPos;
        distance = glm::length(direction);
        direction = glm::normalize(direction);
    }

    void update(double deltaTime);

    QJsonObject save();

    std::string report(std::string const & msg) const
    {
        return DynamicNonInter::report(msg) + "Stand <- " + msg;
    }

};






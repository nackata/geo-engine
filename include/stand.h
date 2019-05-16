#pragma once

#include "dynamicnoninter.h"

#include <glm/glm.hpp>

class Stand : public DynamicNonInter
{
    double velocity = 0; // degrees per second

    glm::vec3 newPos;
    glm::vec3 oldPos;
    double distance;
    glm::vec3 direction;

    float path = 0.0;

    bool move = false;
public:
    Stand(std::string fileName, std::string ID) : DynamicNonInter(fileName, ID) {}

    void setVelocity(double vel) { velocity = vel; }
    double veloc() { return velocity; }

    void translate(glm::vec3 newPosition) {
        oldPos = model.getPosition();
        newPos = newPosition;
        direction = newPos - oldPos;
        distance = glm::length(direction);
        direction = glm::normalize(direction);
    }

    void setMove(bool isMove) { move = isMove; }

    void update(double deltaTime);

    QJsonObject save();

    std::string report(std::string const & msg) const
    {
        return DynamicNonInter::report(msg) + "Stand <- " + msg;
    }

};




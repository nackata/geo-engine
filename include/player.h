#pragma once

#include "fpsCam.h"
#include "sceneobject.h"
#include "aabb.h"
#include <lib/glm/glm.hpp>
#include <vector>

class Player
{
    FpsCam camera;

    std::vector<Object *> collisionObj;
public:
    FpsCam * getCameraPtr() { return &camera; }

    void addObj(Object * obj) { collisionObj.push_back(obj); }

    AABB box;

    Player();

    bool checkCollision();

    void setAction(bool act) { camera.setAction(act); }

    void setPosition(glm::vec3 pos) {
        camera.setPos(pos);
        box.setPos(pos);
    }

    void setDirection(float yaw, float pitch) {
        camera.setDirection(yaw, pitch);
    }

    float getYaw() { return camera.getYaw(); }
    float getPitch() { return camera.getPitch(); }

    glm::vec3 getPosition() { return camera.getPos(); }
    glm::vec3 getDirection() { return camera.getDir(); }

    void processKeyBoardInput(keyBoardIn input, double deltaTime);
    void processMouseMovement(double xoffset, double yoffset, bool constraint = true);
};




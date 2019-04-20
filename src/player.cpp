#include "../include/player.h"

Player::Player()
{
    box.setPos(camera.getPos());

    box.setLen(glm::vec3(0.3, 0.8, 0.3));
}

void Player::processKeyBoardInput(keyBoardIn input, double deltaTime)
{
    glm::vec3 oldPos = camera.getPos();

    camera.processKeyBoardInput(input, deltaTime);
    box.setPos(camera.getPos());

    if (checkCollision())
    {
        glm::vec3 newPos = camera.getPos();

        box.setPos(oldPos.x, newPos.y, newPos.z);

        if(checkCollision())
        {
            box.setPos(newPos.x, newPos.y, oldPos.z);
            if(checkCollision()) {box.setPos(oldPos); }
        }
    }

    camera.setPos(box.getCenter());
}

void Player::processMouseMovement(double xoffset, double yoffset, bool constraint)
{
    camera.processMouseMovement(xoffset, yoffset, constraint);
}

bool Player::checkCollision()
{
    for (Object * obj : collisionObj)
    {
        if (obj->aabbIntersects(box)) return true;
    }

    return false;
}


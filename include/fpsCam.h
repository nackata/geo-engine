#pragma once

//@todo direction down(up) low speed (movement vector XoY)

// connect GLM LIB
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// default parameters

enum keyBoardIn
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

const float SPEED = 2.5;
const float SENSIVITY = 0.1;
const float ZOOM = 45.0;
const float PITCH = 0.0;
const float YAW = 90.0;

const glm::vec3 CAM_POS(0.0, 0.0, 3.0);
const glm::vec3 CAM_DIR(0.0, 0.0, -1.0);
const glm::vec3 CAM_UP(0.0, 1.0, 0.0);

class FpsCam
{
    float mouseSensivity;
    float movementSpeed;

    float yaw;
    float pitch;

    float zoom;

    bool actionButton = false;
    bool deletionButton = false;

    glm::vec3 camPos;
    glm::vec3 camDir;
    glm::vec3 camWorldUp;
    glm::vec3 right;
    glm::vec3 up;

    glm::mat4 calculateViewTranslation(glm::vec3 position);
    glm::mat4 calculateViewRotation(glm::vec3 position, glm::vec3 target, glm::vec3 camWorldUp);
    glm::mat4 calculate_lookAt_matrix(glm::vec3 position, glm::vec3 target, glm::vec3 camWorldUp);
    void updateVec();
public:
    FpsCam(glm::vec3 position = CAM_POS, glm::vec3 direction = CAM_DIR, glm::vec3 camWorldUp = CAM_UP);

    glm::mat4 getView();

    glm::mat4 getViewTranslation();
    glm::mat4 getViewRotation();

    glm::vec3 getPos();
    glm::vec3 getDir();

    float getYaw() { return yaw; }
    float getPitch() { return pitch; }

    void setPos(glm::vec3 pos) { camPos = pos; }
    void setPos(float x, float y, float z) { camPos.x = x;
                                             camPos.y = y;
                                             camPos.z = z; }

    void setDirection(float yaw, float pitch) {
        this->yaw = yaw;
        this->pitch = pitch;

        updateVec();
    }

    void setAction(bool act) { actionButton = act; }
    bool action() { return actionButton; }

    void setDeletion(bool deletion) { deletionButton = deletion; }
    bool deletion() { return deletionButton; }

    void processKeyBoardInput(keyBoardIn input, double deltaTime);
    void processMouseMovement(double xoffset, double yoffset, bool constraint = true);
};

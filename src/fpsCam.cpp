#include "../include/fpsCam.h"

FpsCam::FpsCam(glm::vec3 position, glm::vec3 direction, glm::vec3 worldUp) : mouseSensivity(SENSIVITY), movementSpeed(SPEED), yaw(YAW), pitch(PITCH)
{
    camPos = position;
    camDir = direction;
    camWorldUp = worldUp;

    updateVec();
}

glm::mat4 FpsCam::getView()
{
    return calculate_lookAt_matrix(this->camPos, this->camDir + this->camPos, this->camWorldUp);
}

void FpsCam::processKeyBoardInput(keyBoardIn input, double deltaTime)
{
    float velocity = movementSpeed * static_cast<float>(deltaTime);

    switch (input)
    {
        case FORWARD:
            camPos += camDir * velocity;
            break;
        case BACKWARD:
            camPos -= camDir * velocity;
            break;
        case LEFT:
            camPos -= right * velocity;
            break;
        case RIGHT:
            camPos += right * velocity;
            break;
        case UP:
            camPos += up * velocity;
            break;
        case DOWN:
            camPos -= up * velocity;
    }

     camPos.y = 0.0;
}

void FpsCam::processMouseMovement(double xoffset, double yoffset, bool constraint)
{
    yaw += static_cast<float>(xoffset) * mouseSensivity;
    pitch += -static_cast<float>(yoffset) * mouseSensivity;

    if (constraint)
    {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
    }

    updateVec();
}

void FpsCam::updateVec()
{
    camDir.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
    camDir.y = sin(glm::radians(pitch));
    camDir.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

    camDir = glm::normalize(camDir);


    right = glm::normalize(glm::cross(camDir, camWorldUp));
    up = glm::normalize(glm::cross(right, camDir));
}

glm::vec3 FpsCam::getPos()
{
    return camPos;
}

glm::vec3 FpsCam::getDir()
{
    return camDir;
}

glm::mat4 FpsCam::calculate_lookAt_matrix(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp)
{

    // Create translation and rotation matrix
    // In glm we access elements as mat[col][row] due to column-major layout
    
    glm::mat4 translation = calculateViewTranslation(position);
    glm::mat4 rotation = calculateViewRotation(position, target, worldUp);

    // Return lookAt matrix as combination of translation and rotation matrix
    return rotation * translation; // Remember to read from right to left (first translation then rotation)
}

glm::mat4 FpsCam::calculateViewTranslation(glm::vec3 position)
{
    glm::mat4 translation(1.0); // Identity matrix by default
    translation[3][0] = -position.x; // Third column, first row
    translation[3][1] = -position.y;
    translation[3][2] = -position.z;

    return translation;
}

glm::mat4 FpsCam::calculateViewRotation(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp)
{
    glm::vec3 zaxis = glm::normalize(position - target);
    // 3. Get positive right axis vector
    glm::vec3 xaxis = glm::normalize(glm::cross(glm::normalize(worldUp), zaxis));
    // 4. Calculate camera up vector
    glm::vec3 yaxis = glm::cross(zaxis, xaxis);

    glm::mat4 rotation(1.0);
    rotation[0][0] = xaxis.x; // First column, first row
    rotation[1][0] = xaxis.y;
    rotation[2][0] = xaxis.z;
    rotation[0][1] = yaxis.x; // First column, second row
    rotation[1][1] = yaxis.y;
    rotation[2][1] = yaxis.z;
    rotation[0][2] = zaxis.x; // First column, third row
    rotation[1][2] = zaxis.y;
    rotation[2][2] = zaxis.z; 

    return rotation;
}

glm::mat4 FpsCam::getViewTranslation()
{
    return calculateViewTranslation(this->camPos);
}

glm::mat4 FpsCam::getViewRotation()
{
    return calculateViewRotation(this->camPos, this->camDir + this->camPos, this->camWorldUp);
}

#pragma once

#include "aabb.h"
#include "model.h"
#include "tojsonconvert.h"

class Object
{   
    std::string modelPath;
public:
    bool collisionCheck = false;

    std::string & getModelPath() { return modelPath; }
    Object(std::string modelPath);

    Model model;

    bool aabbIntersects(AABB & a);
};

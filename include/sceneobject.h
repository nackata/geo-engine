#pragma once

#include "aabb.h"
#include "model.h"
#include "tojsonconvert.h"
#include "testalgo.h"

class Object
{   
    std::string modelPath;
public:
    bool collisionCheck = false;

    std::string & getModelPath() { return modelPath; }
    Object(std::string modelPath);

    Model model;

    bool aabbIntersects(AABB & a);

    virtual std::string report(std::string const & msg) const
    {
        return "Object <- ";
    }

};

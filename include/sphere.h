#pragma once

#include "staticobject.h"

class Sphere : public StaticObject
{
public:
    Sphere(std::string modelPath) : StaticObject(modelPath) {}

    StaticObject * clone(std::string modelPath)
    {
        return new Sphere(modelPath);
    }

    std::string report(std::string const & msg) const
    {
        return StaticObject::report(msg) + "Stella <- " + msg;
    }
};

#pragma once

#include "staticobject.h"

class Stella : public StaticObject
{
public:
    Stella(std::string modelPath) : StaticObject(modelPath) {}

    StaticObject * clone(std::string modelPath)
    {
        return new Stella(modelPath);
    }

    std::string report(std::string const & msg) const
    {
        return StaticObject::report(msg) + "Sphere <- " + msg;
    }
};

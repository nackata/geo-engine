#pragma once

#include "sceneobject.h"

class StaticObject : public Object
{

public:
    StaticObject(std::string modelPath) : Object(modelPath) {}

    virtual StaticObject * clone(std::string modelPath) = 0;

    virtual std::string report(std::string const & msg) const
    {
        return Object::report(msg) + "Static <- ";
    }

};

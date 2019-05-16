#pragma once

#include "staticobject.h"

class Room : public StaticObject
{
public:
    Room(std::string modelPath) : StaticObject(modelPath) {}

    StaticObject * clone(std::string modelPath)
    {
        return new Room(modelPath);
    }

    std::string report(std::string const & msg) const
    {
        return StaticObject::report(msg) + "Room <- " + msg;
    }
};

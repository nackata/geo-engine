#pragma once

#include "staticobject.h"

class Room : public StaticObject
{
public:
    Room(std::string modelPath) : StaticObject(modelPath) {}
};

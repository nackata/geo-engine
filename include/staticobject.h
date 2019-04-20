#pragma once

#include "sceneobject.h"

class StaticObject : public Object
{
public:
    StaticObject(std::string modelPath) : Object(modelPath) {}
};

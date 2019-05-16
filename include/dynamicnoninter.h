#pragma once

#include "dynamicobject.h"

class DynamicNonInter : public DynamicObject
{
public:
    DynamicNonInter(std::string & modelPath, std::string &ID) : DynamicObject(modelPath, ID) {}

    virtual void update(double deltaTime) = 0;

    virtual std::string report(std::string const & msg) const
    {
        return DynamicObject::report(msg) + "Non interactive <- ";
    }
};




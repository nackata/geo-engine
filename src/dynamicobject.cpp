#include "../include/dynamicobject.h"

DynamicObject::DynamicObject(std::string &fileName, std::string &ID) : Object(fileName)
{
    this->ID = ID;
}

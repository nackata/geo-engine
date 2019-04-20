#pragma once


#include "sceneobject.h"
#include <vector>
#include <string>

#include <QJsonObject>
#include <QJsonArray>

class DynamicObject : public Object
{
    std::string ID;

public:

    bool finish() { return _finish; }

    virtual QJsonObject save() = 0;

    DynamicObject(std::string &fileName, std::string &ID);

    void addDepenendency(DynamicObject * obj) { dependencies.push_back(obj); }
    bool isTrigerred() { return trigerred; }

    std::string & getId() { return ID; }

    std::vector<DynamicObject*> getDepend() { return dependencies; }
protected:
    std::vector<DynamicObject*> dependencies;

    bool _finish = false;
    bool trigerred = false;
};

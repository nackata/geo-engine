#pragma once

#include "dynamicinter.h"

class Button : public DynamicInter
{
public:
    void update(double deltaTime, FpsCam &cam);

    Button(std::string modelPath, std::string ID) : DynamicInter(modelPath, ID) {}

    QJsonObject save();
};






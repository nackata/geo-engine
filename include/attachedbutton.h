#pragma once

#include "dynamicinter.h"

class AttachedButton : public DynamicInter
{
public:
    void update(double deltaTime, FpsCam &cam);

    AttachedButton(std::string modelPath, std::string ID) : DynamicInter(modelPath, ID) {}

    QJsonObject save();
};






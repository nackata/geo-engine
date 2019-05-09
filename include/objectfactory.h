#pragma once

#include "../include/room.h"
#include "../include/button.h"
#include "../include/attachedbutton.h"
#include "../include/stand.h"
#include "../include/rotatingcube.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

class ObjectFactory
{

    enum InterObjType
    {
        ATTACHED_BUTTON,
        BUTTON
    };

    enum NonInterObjType
    {
        ROTATING_CUBE,
        STAND
    };

    static InterObjType interType(const std::string & id);
    static NonInterObjType nonInterType(const std::string & id);

public:

    static Room * createStaticObject(QJsonObject & staticObj);
    static DynamicNonInter * createNonInterObject(QJsonObject & obj);
    static DynamicInter * createInterObject(QJsonObject & obj);
};

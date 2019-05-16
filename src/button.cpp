#include "../include/button.h"

void Button::update(double deltaTime, FpsCam &cam)
{
    trigerred = false;

    if (timer > 0)
        timer -= deltaTime;

    if (timer > 0) return;

    if (cam.action() && checkIsTriggered(cam))
    {
        timer = 10.0;
        this->trigerred = true;
    }

    if (cam.deletion() && checkIsTriggered(cam))
    {
        timer = 10.0;
        model.switchRender();
    }
}

QJsonObject Button::save()
{
    QJsonObject dynInterObj;
    dynInterObj.insert("filename", QString::fromStdString(getModelPath()));
    dynInterObj.insert("ID", QString::fromStdString(getId()));
    dynInterObj.insert("scale", ToJson::vectorToObj(model.getScale()));
    dynInterObj.insert("position", ToJson::vectorToObj(model.getPosition()));
    dynInterObj.insert("rotation", ToJson::quatToObj(model.getRotation()));
    dynInterObj.insert("collision_check", collisionCheck);
    QJsonArray dependArr;
    for (DynamicObject * dep : getDepend())
    {
        QJsonObject dependencyObj;
        dependencyObj.insert("ID", QString::fromStdString(dep->getId()));
        dependArr.append(dependencyObj);
    }
    dynInterObj.insert("dependencies", dependArr);

    return dynInterObj;
}

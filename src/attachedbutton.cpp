#include "../include/attachedbutton.h"

void AttachedButton::update(double deltaTime, FpsCam &cam)
{
    trigerred = false;

    if (timer > 0)
        timer -= deltaTime;

    if (timer > 0) return;

    if (cam.action() && checkIsTriggered(cam))
    {
        timer = 10.0;
        this->trigerred = !this->trigerred;
        _finish = true;
    }

    if (dependencies.size() == 0) return;

    model.setPosition(dependencies[0]->model.getPosition().x,
                      dependencies[0]->model.getPosition().y + 0.918,
                      dependencies[0]->model.getPosition().z - 0.03);


}

QJsonObject AttachedButton::save()
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


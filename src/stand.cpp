#include "../include/stand.h"

void Stand::update(double deltaTime)
{
    if (dependencies.size() != 3) return;

    move = dependencies[0]->isTrigerred() && dependencies[1]->isTrigerred() && dependencies[2]->isTrigerred();

    if (!move) return;

    float dist = deltaTime * velocity + path;

    glm::vec3 currPos = oldPos + (direction * dist);

    if (glm::length(currPos - oldPos) > distance)
    {
        move = false;
        return;
    }

    model.setPosition(currPos);

    path = dist;
}

QJsonObject Stand::save()
{
    QJsonObject dynInterObj;
    dynInterObj.insert("filename", QString::fromStdString(getModelPath()));
    dynInterObj.insert("ID", QString::fromStdString(getId()));
    dynInterObj.insert("scale", ToJson::vectorToObj(model.getScale()));
    dynInterObj.insert("position", ToJson::vectorToObj(model.getPosition()));
    dynInterObj.insert("rotation", ToJson::quatToObj(model.getRotation()));
    QJsonArray dependArr;
    for (DynamicObject * dep : getDepend())
    {
        QJsonObject dependencyObj;
        dependencyObj.insert("ID", QString::fromStdString(dep->getId()));
        dependArr.append(dependencyObj);
    }
    dynInterObj.insert("dependencies", dependArr);

    dynInterObj.insert("new_position", ToJson::vectorToObj(this->newPos));
    dynInterObj.insert("velocity", velocity);

    return dynInterObj;
}


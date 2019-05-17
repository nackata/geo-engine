#include "../include/stand.h"

void Stand::update(double deltaTime)
{
    current->update(deltaTime, *this);
}

QJsonObject Stand::save()
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

    dynInterObj.insert("new_position", ToJson::vectorToObj(this->newPos));
    dynInterObj.insert("velocity", velocity);

    return dynInterObj;
}




void MovingState::update(double deltaTime, Stand & stand)
{

    if (!(stand.dependencies[0]->isTrigerred() &&
        stand.dependencies[1]->isTrigerred() &&
        stand.dependencies[2]->isTrigerred()))
    {
        stand.setState(new StandingState);
        return;
    }

    float dist = deltaTime * stand.velocity + stand.path;

    glm::vec3 currPos = stand.oldPos + (stand.direction * dist);

    if (glm::length(currPos - stand.oldPos) > stand.distance)
    {
        stand.setState(new StandingState);
        return;
    }

    stand.model.setPosition(currPos);

    stand.path = dist;
}

void StandingState::update(double deltaTime, Stand & stand)
{
    if (stand.dependencies.size() != 3) return;

    if (stand.dependencies[0]->isTrigerred() &&
        stand.dependencies[1]->isTrigerred() &&
        stand.dependencies[2]->isTrigerred())
    {
        stand.setState(new MovingState);
    }
}

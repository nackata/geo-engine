#include "../include/rotatingcube.h"

void RotatingCube::update(double deltaTime)
{

    double needVel = velocity;

    bool trig = false;
    for (DynamicObject * obj : dependencies)
    {
        if (obj->isTrigerred())
            trig = true;
    }

    if (trig)
    {
        if (currentState == STATE_PURPLE) currentState = STATE_BLACK;
        else currentState = (state)(currentState + 1);
        model.setDiffuseColor(getRgbColor(currentState));
    }

    double angle = needVel * deltaTime;

//    model.addRotation(axis, glm::radians(angle));

    if (currentState == needState) trigerred = true;
    else trigerred = false;

}

glm::vec3 RotatingCube::getRgbColor(RotatingCube::state st)
{
    switch (st)
    {
        case RotatingCube::STATE_BLACK:
            return Color::getColor(COLOR_BLACK);
        case RotatingCube::STATE_WHITE:
            return Color::getColor(COLOR_WHITE);
        case RotatingCube::STATE_RED:
            return Color::getColor(COLOR_RED);
        case RotatingCube::STATE_GREEN:
            return Color::getColor(COLOR_GREEN);
        case RotatingCube::STATE_BLUE:
            return Color::getColor(COLOR_BLUE);
        case RotatingCube::STATE_YELLOW:
            return Color::getColor(COLOR_YELLOW);
        case RotatingCube::STATE_PURPLE:
            return Color::getColor(COLOR_PURPLE);
        default:
            return Color::getColor(COLOR_BLACK);
    }
}

QJsonObject RotatingCube::save()
{
    QJsonObject dynInterObj;
    dynInterObj.insert("filename", QString::fromStdString(getModelPath()));
    dynInterObj.insert("ID", QString::fromStdString(getId()));
    dynInterObj.insert("scale", ToJson::vectorToObj(model.getScale()));
    dynInterObj.insert("position", ToJson::vectorToObj(model.getPosition()));
    dynInterObj.insert("rotation", ToJson::quatToObj(model.getRotation()));
    dynInterObj.insert("current_state", static_cast<int>(currentState));
    dynInterObj.insert("need_state", static_cast<int>(needState));
    QJsonArray dependArr;
    for (DynamicObject * dep : getDepend())
    {
        QJsonObject dependencyObj;
        dependencyObj.insert("ID", QString::fromStdString(dep->getId()));
        dependArr.append(dependencyObj);
    }
    dynInterObj.insert("dependencies", dependArr);

    dynInterObj.insert("axes", ToJson::vectorToObj(this->axis));
    dynInterObj.insert("velocity", velocity);

    return dynInterObj;
}

#include "../include/objectfactory.h"

std::array<StaticObject*, 3> ObjectFactory::prototypes =
{
   new Room("dummy"),
   new Stella("dummy"),
   new Sphere("dummy")
};


ObjectFactory::InterObjType ObjectFactory::interType(const std::__cxx11::string &id)
{
    std::string type = id.substr(1, 4);

    int number = std::stoi(type) - 1;

    return (InterObjType)number;
}

ObjectFactory::NonInterObjType ObjectFactory::nonInterType(const std::__cxx11::string &id)
{
    std::string type = id.substr(1, 4);

    int number = std::stoi(type) - 1;

    return (NonInterObjType)number;
}

StaticObject *ObjectFactory::createStaticObject(QJsonObject &staticObj)
{

    StaticObject * room = prototypes.at(0)->clone(staticObj.value("fileName").toString().toStdString());

    room->collisionCheck = staticObj.value("collision_check").toBool();

    std::cout << room->report("created!") << std::endl;
    return room;
}

DynamicNonInter *ObjectFactory::createNonInterObject(QJsonObject &obj)
{
    NonInterObjType type = nonInterType(obj.value("ID").toString().toStdString());

    DynamicNonInter * object = nullptr;

    switch (type)
    {
        case STAND:
        {
            Stand * stand = new Stand(obj.value("filename").toString().toStdString(),
                                      obj.value("ID").toString().toStdString());
            stand->model.setPosition(ToJson::objToVec(obj.value("position").toObject()));
            stand->model.setRotation(ToJson::objToQuat(obj.value("rotation").toObject()));
            stand->model.setScale(ToJson::objToVec(obj.value("scale").toObject()));
            stand->translate(ToJson::objToVec(obj.value("new_position").toObject()));
            stand->setVelocity(obj.value("velocity").toDouble());
            stand->collisionCheck = obj.value("collision_check").toBool();

            object = static_cast<DynamicNonInter*>(stand);
            break;
        }
        case ROTATING_CUBE:
        {
            RotatingCube * cube = new RotatingCube(obj.value("filename").toString().toStdString(),
                                      obj.value("ID").toString().toStdString());
            cube->model.setPosition(ToJson::objToVec(obj.value("position").toObject()));
            cube->model.setRotation(ToJson::objToQuat(obj.value("rotation").toObject()));
            cube->model.setScale(ToJson::objToVec(obj.value("scale").toObject()));
            cube->setVelocity(obj.value("velocity").toDouble());
            cube->setNeedState((RotatingCube::state)obj.value("need_state").toInt());
            cube->setCurrState((RotatingCube::state)obj.value("current_state").toInt());
            cube->setAxis(ToJson::objToVec(obj.value("axes").toObject()));
            cube->collisionCheck = obj.value("collision_check").toBool();

            object = static_cast<DynamicNonInter*>(cube);
            break;
        }
        default:
            return nullptr;
    }

    std::cout << object->report("created!") << std::endl;
    return object;

}

DynamicInter *ObjectFactory::createInterObject(QJsonObject &dynObj)
{
    InterObjType type = interType(dynObj.value("ID").toString().toStdString());

    DynamicInter * object = nullptr;

    switch (type)
    {
        case InterObjType::BUTTON:
        {
            Button * but = new Button(dynObj.value("filename").toString().toStdString(),
                                      dynObj.value("ID").toString().toStdString());
            but->model.setPosition(ToJson::objToVec(dynObj.value("position").toObject()));
            but->model.setRotation(ToJson::objToQuat(dynObj.value("rotation").toObject()));
            but->model.setScale(ToJson::objToVec(dynObj.value("scale").toObject()));
            but->collisionCheck = dynObj.value("collision_check").toBool();

            object = static_cast<DynamicInter*>(but);
            break;
        }
        case InterObjType::ATTACHED_BUTTON:
        {
            AttachedButton * but = new AttachedButton(dynObj.value("filename").toString().toStdString(),
                                      dynObj.value("ID").toString().toStdString());
            but->model.setPosition(ToJson::objToVec(dynObj.value("position").toObject()));
            but->model.setRotation(ToJson::objToQuat(dynObj.value("rotation").toObject()));
            but->model.setScale(ToJson::objToVec(dynObj.value("scale").toObject()));
            but->collisionCheck = dynObj.value("collision_check").toBool();

            object = static_cast<DynamicInter*>(but);
            break;
        }
        default:
            return nullptr;
    }

    std::cout << object->report("created!") << std::endl;
    return object;
}

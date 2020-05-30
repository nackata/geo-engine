#include "../include/game.h"

bool Game::save(std::string fileName)
{
    QString qName = QString::fromStdString(fileName);

    QFileInfo finf(qName);

    QString extension = finf.completeSuffix();

    if (extension != "json") return false;

    return toJsonFile(qName);
}

bool Game::toJsonFile(QString & name)
{
    std::string jsonString;

    jsonString = getJsonString();

    std::ofstream jsonOFile;

    try
    {
        jsonOFile.open(name.toStdString());

        jsonOFile << jsonString;

        jsonOFile.close();

    } catch (std::ofstream::failure e){
        return false;
    }

    return true;
}

std::string Game::getJsonString()
{
    QJsonDocument doc;
    QJsonObject gameObj;

    QJsonObject playerObj;

    playerObj.insert("cam_yaw", player.getYaw());
    playerObj.insert("cam_pitch", player.getPitch());
    playerObj.insert("cam_position", ToJson::vectorToObj(player.getPosition()));

    gameObj.insert("Player", playerObj);

    QJsonObject sceneObjectsObj;

    QJsonArray staticObjArr;
    for (StaticObject * stObj : scene.staticObjects())
    {
        QJsonObject staticObj;
        staticObj.insert("fileName", QString::fromStdString(stObj->getModelPath()));
        staticObj.insert("collision_check", stObj->collisionCheck);
        staticObjArr.append(staticObj);
    }

    sceneObjectsObj.insert("static_objects", staticObjArr);

    QJsonArray dynamicObjArr;
    for (DynamicInter * dynInt : scene.dynamicInterObjects())
    {
        QJsonObject dynInterObj = dynInt->save();

        dynamicObjArr.append(dynInterObj);
    }

    for (DynamicNonInter * dynInt : scene.dynamicNonInterObjects())
    {
        QJsonObject dynNonInterObj = dynInt->save();

        dynamicObjArr.append(dynNonInterObj);
    }

    sceneObjectsObj.insert("dynamic_objects", dynamicObjArr);

    gameObj.insert("Objects", sceneObjectsObj);

    QJsonArray lightArr;
    for (Light * l : scene.lights())
    {
        QJsonObject lightObj;
        lightObj.insert("position", ToJson::vectorToObj(l->position()));

        lightArr.append(lightObj);
    }

    gameObj.insert("lights", lightArr);

    doc.setObject(gameObj);

    return doc.toJson().toStdString();
}

Game::ObjectType Game::getClass(const std::string & id)
{
    std::string type = id.substr(0, 3);

    int number = std::stoi(type) - 1;

    return static_cast<ObjectType>(number);
}

bool Game::load(std::string fileName)
{
    QString qName = QString::fromStdString(fileName);

    QFileInfo finf(qName);

    if (!finf.exists()) return false;

    QString extension = finf.completeSuffix();

    if (extension != "json") return false;

    fromJsonFile(qName);

    return true;
}

bool Game::fromJsonFile(QString & fileName)
{
    std::string jsonString;

    try
    {
        std::ifstream jsonFile;

        jsonFile.open(fileName.toStdString());

        std::stringstream jsonStream;

        jsonStream << jsonFile.rdbuf();

        jsonFile.close();

        jsonString = jsonStream.str();
    } catch(std::fstream::failure e) { return false; }

    jsonStringToEntities(jsonString);

    return true;
}



bool Game::jsonStringToEntities(std::string & jsonStr)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(QByteArray::fromStdString(jsonStr), &err);
    if (err.error != QJsonParseError::NoError)
    {
        return false;
    }

    QJsonObject gameObj = doc.object();

    QJsonObject playerObj = gameObj.value("Player").toObject();

    // Player properities

    player.setPosition(ToJson::objToVec(playerObj.value("cam_position").toObject()));
    player.setDirection(playerObj.value("cam_yaw").toDouble(),
                        playerObj.value("cam_pitch").toDouble());

    // lights

    QJsonArray lightsArr = gameObj.value("lights").toArray();

    for (int i = 0; i < lightsArr.size(); ++i)
    {
        QJsonObject lightObj = lightsArr.at(i).toObject();

        Light * light = new Light;
        light->setPosition(ToJson::objToVec(lightObj.value("position").toObject()));

        scene.addLight(light);
        renderer.addLight(light);
    }

    // static objects

    QJsonObject objectsObj = gameObj.value("Objects").toObject();

    QJsonArray staticObjArr = objectsObj.value("static_objects").toArray();

    for (int i = 0; i < staticObjArr.size(); ++i)
    {
        QJsonObject staticObj = staticObjArr.at(i).toObject();
        Room * room = new Room(staticObj.value("fileName").toString().toStdString());
        room->collisionCheck = staticObj.value("collision_check").toBool();
        bool cullInverse = staticObj.value("cull_inverse").toBool();

        if (cullInverse)
        {
            room->model.setCullFaceFront(false);
        }

        scene.addObj(room);
        renderer.addObj(room);
        if (room->collisionCheck)
            player.addObj(room);
    }

    // dynamic objects

    QJsonArray dynamicObjArr = objectsObj.value("dynamic_objects").toArray();
    std::vector<QJsonObject> objectsWithDpn;

    for (int i = 0; i < dynamicObjArr.size(); ++i)
    {
        QJsonObject dynObj = dynamicObjArr.at(i).toObject();

        ObjectType type = getClass(dynObj.value("ID").toString().toStdString());

        if (type == BUTTON || type == ATTACHED_BUTTON)
        {
            DynamicInter * obj = getDynamicInterObj(dynObj, type);
            if (obj == nullptr) continue;
            scene.addObj(obj);
            renderer.addObj(obj);
        }
        else
        {
            DynamicNonInter * obj = getDynamicNonInterObj(dynObj, type);
            if (obj == nullptr) continue;
            scene.addObj(obj);
            renderer.addObj(obj);
        }

        QJsonArray dpnArr = dynObj.value("dependencies").toArray();

        if (dpnArr.size() > 0)
            objectsWithDpn.push_back(dynObj);
    }

    for (QJsonObject & jsonObj : objectsWithDpn)
    {
        DynamicObject * object = scene.search(jsonObj.value("ID").toString().toStdString());

        QJsonArray dpnArr = jsonObj.value("dependencies").toArray();

        for (int i = 0; i < dpnArr.size(); ++i)
        {
            std::string id = dpnArr.at(i).toObject().value("ID").toString().toStdString();

            object->addDepenendency(scene.search(id));
        }
    }

    return true;
}

DynamicInter * Game::getDynamicInterObj(QJsonObject & dynObj, ObjectType type)
{
    switch (type)
    {
        case BUTTON:
        {
            Button * but = new Button(dynObj.value("filename").toString().toStdString(),
                                      dynObj.value("ID").toString().toStdString());
            but->model.setPosition(ToJson::objToVec(dynObj.value("position").toObject()));
            but->model.setRotation(ToJson::objToQuat(dynObj.value("rotation").toObject()));
            but->model.setScale(ToJson::objToVec(dynObj.value("scale").toObject()));

            return but;
        }
        case ATTACHED_BUTTON:
        {
            AttachedButton * but = new AttachedButton(dynObj.value("filename").toString().toStdString(),
                                      dynObj.value("ID").toString().toStdString());
            but->model.setPosition(ToJson::objToVec(dynObj.value("position").toObject()));
            but->model.setRotation(ToJson::objToQuat(dynObj.value("rotation").toObject()));
            but->model.setScale(ToJson::objToVec(dynObj.value("scale").toObject()));

            return but;
        }
        default:
            return nullptr;
    }


}

DynamicNonInter * Game::getDynamicNonInterObj(QJsonObject & obj, ObjectType type)
{
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
            player.addObj(stand);

            return stand;
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

            return cube;
        }
        default:
            return nullptr;
    }
}

bool Game::shouldClose()
{
   if (renderer.shouldClose()) return true;

   if (scene.finished())
   {
       currentStr.str = "YOU WON! Press esc to leave";
       currentStr.x = 600;
       currentStr.y = 100;
       currentStr.scale = 1.5;
   }

   return false;
}

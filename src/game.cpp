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
    int type = (id.at(0) - '0') - 1;

    return (ObjectType)type;
}

bool Game::load(std::string fileName)
{
    QString qName = QString::fromStdString(fileName);

    QFileInfo finf(qName);

    if (!finf.exists()) return false;

    QString extension = finf.completeSuffix();

    if (extension != "json") return false;

    return fromJsonFile(qName);
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

    return jsonStringToEntities(jsonString);
}



bool Game::jsonStringToEntities(std::string & jsonStr)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(QByteArray::fromStdString(jsonStr), &err);

    if (err.error != QJsonParseError::NoError)  return false;

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

        Room * room = ObjectFactory::createStaticObject(staticObj);

        if (room) addObj(room);

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

        if (type == ObjectType::Interactive)
        {
            DynamicInter * obj = ObjectFactory::createInterObject(dynObj);

            if (obj) addObj(obj);

            if (obj->collisionCheck)
                player.addObj(obj);
        }

        if (type == ObjectType::NonInteractive)
        {
            DynamicNonInter * obj = ObjectFactory::createNonInterObject(dynObj);

            if (obj) addObj(obj);

            if (obj->collisionCheck)
                player.addObj(obj);
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

// eto tupa pashalka v kode, krasava

void Game::addObj(StaticObject *obj)
{
    scene.addObj(obj);
    renderer.addObj(obj);
}

void Game::addObj(DynamicNonInter *obj)
{
    scene.addObj(obj);
    renderer.addObj(obj);
}

void Game::addObj(DynamicInter *obj)
{
    scene.addObj(obj);
    renderer.addObj(obj);
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

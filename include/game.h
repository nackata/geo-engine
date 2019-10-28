#pragma once

#include "scene.h"
#include "renderer.h"
#include "oglrenderer.h"
#include "player.h"
#include "inputmanager.h"
#include "tojsonconvert.h"
#include "room.h"
#include "stand.h"
#include "rotatingcube.h"
#include "button.h"
#include "attachedbutton.h"
#include "screentext.h"
#include "soundmaster.h"
#include "objectfactory.h"

#include "glm/glm.hpp"

#include <iostream>
#include <QString>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

class Game
{

    enum ObjectType
    {
        Interactive,
        NonInteractive,
        Static
    };

    struct ScreenStr
    {
        std::string str;
        int x;
        int y;
        int scale;
    };

    // serialization/deserealization stuff

    bool toJsonFile(QString & name);
    std::string getJsonString();

    bool fromJsonFile(QString & fileName);
    bool jsonStringToEntities(std::string & jsonStr);


    ObjectType getClass(const std::string & id);

    // main parts of game

    ScreenStr currentStr;

    Renderer * renderer;
    InputManager input;
    Player player;
    Scene scene;
    ScreenText text;
    SoundMaster sound;


    void addObj(StaticObject * obj);
    void addObj(DynamicNonInter * obj);
    void addObj(DynamicInter * obj);

    void addObject(Object *obj);

public:

    void drawScene();

    void procInput(std::string const& name = "lol")
    {
        input.processInput(renderer->getDelta(), name);
    }

    void updateScene() {
        scene.updateScene(renderer->getDelta());
        sound.update(scene.dynamicInterObjects());
    }

    bool shouldClose();

    Game();


    bool load(std::string fileName);

    bool save(std::string fileName);
};




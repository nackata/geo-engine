#pragma once

#include "scene.h"
#include "renderer.h"
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

    InputManager input;
    Player player;
    Scene scene;
    Renderer renderer;
    ScreenText text;
    SoundMaster sound;


    void addObj(StaticObject * obj);
    void addObj(DynamicNonInter * obj);
    void addObj(DynamicInter * obj);

public:

    void drawScene() {
        renderer.drawScene();
        text.RenderText(currentStr.str, currentStr.x, currentStr.y, currentStr.scale, glm::vec3(1.0, 1.0, 1.0));
        renderer.swapBuffer();
    }

    void procInput() { input.processInput(renderer.getDelta()); }

    void updateScene() {
        scene.updateScene(renderer.getDelta());
        sound.update(scene.dynamicInterObjects());
    }

    bool shouldClose();

    Game() {
         renderer.setCam(player.getCameraPtr());
         renderer.init();
         scene.setCam(player.getCameraPtr());
         input.setPlayer(&player);
         input.setWin(renderer.getWin());

         text = ScreenText(renderer.getWin());
         currentStr.str = "wasd - move | e - interact | mouse - camera control";
         currentStr.x = 400;
         currentStr.y = 100;
         currentStr.scale = 1.0;

         sound.loopAmbient();
    }


    bool load(std::string fileName);

    bool save(std::string fileName);
};




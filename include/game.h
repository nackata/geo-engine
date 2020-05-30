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

#include "glm/glm.hpp"

#include <iostream>
#include <QString>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <array>

class Game
{
    enum ObjectType
    {
        ROTATING_CUBE,
        STAND,
        ATTACHED_BUTTON,
        BUTTON
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
    DynamicInter * getDynamicInterObj(QJsonObject & obj, ObjectType type);
    DynamicNonInter * getDynamicNonInterObj(QJsonObject & obj, ObjectType type);

    // main parts of game

    double m_time = 0.0;
    int m_counter = 0;
    bool m_fpsMeasure = false;

    ScreenStr currentStr;
    ScreenStr fpsStr;

    InputManager input;
    Player player;
    Scene scene;
    Renderer renderer;
    ScreenText text;
    SoundMaster sound;

    void measureFps(double delta)
    {
        m_time += delta;
        ++m_counter;
        if (m_time > 1.0)
        {
            fpsStr.str = std::to_string(m_counter);
            m_counter = 0;
            m_time = 0.0;
        }
    }

public:

    void drawScene() {
        renderer.drawScene();
        text.RenderText(currentStr.str, currentStr.x, currentStr.y, currentStr.scale, glm::vec3(1.0, 1.0, 1.0));
        text.RenderText(fpsStr.str, fpsStr.x, fpsStr.y, fpsStr.scale, glm::vec3(1.0, 1.0, 1.0));
        renderer.swapBuffer();
    }

    void procInput() { input.processInput(renderer.getDelta()); }

    void updateScene() {
        scene.updateScene(renderer.getDelta());
        sound.update(scene.dynamicInterObjects());

        if (m_fpsMeasure) measureFps(renderer.getDelta());
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

         fpsStr.str = "lolol";
         fpsStr.x = 10;
         fpsStr.y = 500;
         fpsStr.scale = 1.0;


         sound.loopAmbient();
    }


    bool load(std::string fileName);

    bool save(std::string fileName);

    void setFpsMeasure(bool fpsMeasure)
    {
        m_fpsMeasure = fpsMeasure;
    }
};




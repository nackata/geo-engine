#include "../include/soundmaster.h"

void SoundMaster::loopAmbient()
{
   SoundEngine->play2D("common/music/lvl1.mp3", true);
}

void SoundMaster::update(std::vector<DynamicInter*> & objs)
{
    for (DynamicInter * obj : objs)
    {
        if (obj->isTrigerred())
            SoundEngine->play2D("common/music/button.wav");
    }
}


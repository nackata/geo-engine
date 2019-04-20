#pragma once

#include <irrKlang.h>
#include <string>
#include <vector>

#include "dynamicinter.h"

using namespace irrklang;

class SoundMaster
{
    ISoundEngine *SoundEngine;
public:
    SoundMaster() { SoundEngine = createIrrKlangDevice(); }

    void loopAmbient();
    void update(std::vector<DynamicInter*> & objs);
};




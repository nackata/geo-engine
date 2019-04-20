#include "../include/scene.h"

void Scene::updateScene(double delta)
{
    for (DynamicNonInter * obj : dynNonInterObj)
    {
        obj->update(delta);
    }

    for (DynamicInter * obj : dynInterObj)
    {
        obj->update(delta, *camera);

        if (obj->finish()) finish = true;
    }
}

DynamicObject * Scene::search(std::string ID)
{
    for (DynamicInter * obj : dynInterObj)
    {
        if (obj->getId() == ID)
            return obj;
    }

    for (DynamicNonInter * obj : dynNonInterObj)
    {
        if (obj->getId() == ID)
            return obj;
    }

    return nullptr;
}

#define STB_IMAGE_IMPLEMENTATION

#include <iostream>

#include "include/game.h"

int main()
{
    std::cout << "game loading" << std::endl;

    Game game;

    // load level
    if (!game.load("firstSave.json"))
    {
        std::cout << "Loading failed" << std::endl;
        throw std::runtime_error("");
    }

    while (!game.shouldClose()) //    game loop
    {
        game.procInput();

        game.updateScene();

        game.drawScene();
    }    

    // save progress
//    if (!game.save("firstSave.json")) std::cout << "problem saving" << std::endl;

    std::cout << "lol kek" << std::endl;

    return 0;
}


#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <string>

#include "include/game.h"

int main()
{

    std::string name;
    std::cout << "Enter your name :";
    std::cin >> name;


    Game game;

    // load level
    game.load("firstSave.json");

    while (!game.shouldClose()) //    game loop
    {
        game.procInput(name);

        game.updateScene();

        game.drawScene();
    }    

    // save progress
//    if (!game.save("firstSave.json")) std::cout << "problem saving" << std::endl;

    std::cout << "lol kek" << std::endl;

    return 0;
}


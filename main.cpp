#include <iostream>
#include "Engine.h"
#include "SmithGame.h"
#include "Game.h"

int main()
{
    Engine engine(800, 450);
    SmithGame* game = new SmithGame();
    std::cout << "Beginning: Engine::Run(game);" << std::endl;
    engine.Run(game);
    std::cout << "Finished: Engine::Run(game);" << std::endl;
    delete game;
    std::cout << "Finished: delete game;" << std::endl;
}

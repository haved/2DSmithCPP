#include <iostream>
#include "Engine.h"
#include "SmithGame.h"
#include "Game.h"

int main(int args, char **argv)
{
    Engine engine(800, 450);
    SmithGame* game = new SmithGame(&engine);
    std::cout << "Beginning: Engine::Run(game);" << std::endl;
    engine.Run(game);
    std::cout << "Finished: Engine::Run(game);" << std::endl;
    delete game;
    std::cout << "Finished: delete game;" << std::endl;
	return 0;
}

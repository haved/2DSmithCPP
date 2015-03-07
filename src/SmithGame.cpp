#include "SmithGame.h"
#include "PlayerEntity.h"
#include <memory>

SmithGame::SmithGame()
{
    currentScene = new Scene();
    currentScene->AddEntity(std::make_shared<PlayerEntity>(140, 180, 30, 30, 50, 50));
}

SmithGame::~SmithGame()
{
    delete currentScene;
}

void SmithGame::Update()
{
    currentScene->Update();
}

void SmithGame::Render()
{
    currentScene->Render();
}

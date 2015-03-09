#include "SmithGame.h"
#include "Resources.h"
#include "PlayerEntity.h"
#include "InteractiveEntity.h"
#include "ImageEntity.h"
#include <memory>

SmithGame::SmithGame()
{
    currentScene = new Scene();
    currentScene->AddEntity(std::make_shared<ImageEntity>(0, 0, 800, 450, 0, 0, 800/32, 450/32, std::make_shared<Texture>("res"<<"floor.bmp")));
    currentScene->AddEntity(std::make_shared<InteractiveEntity>(50, 30, 50, 50, 30, 30, std::make_shared<Texture>("res/table.bmp")));
    currentScene->AddEntity(std::make_shared<PlayerEntity>(140, 180, 30, 30, 30, 30));
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

#include "SmithGame.h"
#include "PlayerEntity.h"
#include "InteractiveEntity.h"
#include "ImageEntity.h"
#include "GL/gl.h"
#include <memory>

SmithGame::SmithGame()
{
    currentScene = new Scene();
    player = std::make_shared<PlayerEntity>(140, 180, 56, 64, std::make_shared<Texture>("res/player.png"));
    currentScene->AddEntity(std::make_shared<ImageEntity>(0, 0, 800, 450, 0, 0, 800/32, 450/32, std::make_shared<Texture>("res/floor.bmp")));
    currentScene->AddEntity(std::make_shared<InteractiveEntity>(50, 30, 50, 50, 30, 30, std::make_shared<Texture>("res/table.bmp")));
    currentScene->AddEntity(player);
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
    glPushMatrix();
    glTranslatef(0, 0, 0);
    currentScene->Render();
    glPopMatrix();
}

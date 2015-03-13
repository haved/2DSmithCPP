#include "SmithGame.h"
#include "InteractiveEntity.h"
#include "ImageEntity.h"
#include "GL/gl.h"
#include "Engine.h"

SmithGame::SmithGame(Engine* engine) : Game(engine)
{
    currentScene = new Scene(800, 600);
    player = std::make_shared<PlayerEntity>(140, 180, 56, 64, std::make_shared<Texture>("res/player.png"));
    currentScene->AddEntity(std::make_shared<ImageEntity>(0, 0, 800, 600, 0, 0, 800/32, 600/32, std::make_shared<Texture>("res/floor.bmp")));
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
    float panX = player->getX() - engine->getCanvasWidth()/2;
    float panY = player->getY() - engine->getCanvasHeight()/2;
    if(panX < 0)
        panX = 0;
    if(panY < 0)
        panY = 0;
    if(panX > currentScene->getWidth()-engine->getCanvasWidth())
        panX = currentScene->getWidth()-engine->getCanvasWidth();
    if(panY > currentScene->getHeight()-engine->getCanvasHeight())
        panY = currentScene->getHeight()-engine->getCanvasHeight();
    glTranslatef(-panX, -panY, 0);
    currentScene->Render();
    glPopMatrix();
}

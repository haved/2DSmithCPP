#include "SmithGame.h"
#include "InteractiveEntity.h"
#include "ImageEntity.h"
#include "GL/gl.h"
#include "Engine.h"

SmithGame::SmithGame(Engine* engine) : Game(engine)
{
    currentScene = new Scene(800, 600);
    player = std::make_shared<PlayerEntity>(140, 180, 56, 24, 52, std::make_shared<Texture>("res/player.png"));
    currentScene->AddEntity(player);
    std::shared_ptr<Texture> wallTexture = std::make_shared<Texture>("res/wall.png");
    currentScene->AddEntity(std::make_shared<ImageEntity>(0, 0, 800, 32, 0, 0, 800/32, 1, true, wallTexture));
    currentScene->AddEntity(std::make_shared<ImageEntity>(0, 0, 32, 600, 0, 0, 1, 600/32, true, wallTexture));
    currentScene->AddEntity(std::make_shared<ImageEntity>(768, 0, 800, 600, 800/32-1, 0, 800/32, 600/32, true, wallTexture));
    currentScene->AddEntity(std::make_shared<ImageEntity>(0, 568, 800, 600, 0, 600/32-1, 800/32, 600/32, true, wallTexture));
    currentScene->AddEntity(std::make_shared<InteractiveEntity>(100, 100, 50, 50, 20, 20, 40, std::make_shared<Texture>("res/table.png")));
    currentScene->AddEntity(std::make_shared<ImageEntity>(0, 0, 800, 600, 0, 0, 800/32, 600/32, std::make_shared<Texture>("res/floor.bmp")));
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

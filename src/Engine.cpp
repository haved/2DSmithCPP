#include "Engine.h"
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <GL/gl.h>

#define MIN_TICK_MILLIS 16

float c_width, c_height;

Engine::Engine(int canvas_width, int canvas_height)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    c_width = (float)canvas_width;
    c_height = (float)canvas_height;

    std::string title = "Smith";
    display = new Display(canvas_width, canvas_height, title.c_str());
}

Engine::~Engine()
{
    delete display;
    SDL_Quit();
    std::cout << "Finished: SDL_Quit();" << std::endl;
}

void Engine::Run(Game* game)
{
    while(!display->isClosed())
    {
        PollEvents();
        Input::Update();
        game->Update();
        display->Clear(0.3f, 0.6f, 1, 1);
        glPushMatrix();
        glScalef(display->getWidth()/c_width, display->getHeight()/c_height, 1);
        game->Render();
        glPopMatrix();
        display->Update();
        Time::Next(MIN_TICK_MILLIS);
    }
}

void Engine::PollEvents()
{
    SDL_Event e;

    while(SDL_PollEvent(&e))
        switch(e.type)
        {
            case SDL_QUIT: display->Close(); break;
            case SDL_WINDOWEVENT: if(e.window.event == SDL_WINDOWEVENT_RESIZED) display->Resize(e.window.data1, e.window.data2); break;
            case SDL_MOUSEWHEEL:
                break;
            default: break;
        }
}

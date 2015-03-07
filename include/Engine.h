#ifndef ENGINE_H
#define ENGINE_H

#include "Game.h"
#include "Time.h"
#include "Input.h"
#include "Display.h"

class Engine
{
    public:
        Engine(int c_width, int c_height);
        virtual ~Engine();
        void Run(Game* game);
    protected:
    private:
        Display* display;
        void PollEvents();
};

#endif // ENGINE_H

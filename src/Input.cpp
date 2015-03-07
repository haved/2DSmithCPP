#include "Input.h"
#include <SDL2/SDL.h>

Uint8 upKey = SDL_SCANCODE_W;
Uint8 downKey = SDL_SCANCODE_S;
Uint8 leftKey = SDL_SCANCODE_A;
Uint8 rightKey = SDL_SCANCODE_D;

bool up = false, down = false, left = false, right = false;

void Input::Update()
{
    const Uint8* state = SDL_GetKeyboardState(NULL);

    up=state[upKey]==1;
    down=state[downKey]==1;
    left=state[leftKey]==1;
    right=state[rightKey]==1;
}

bool Input::isUpKeyDown(){return up;}
bool Input::isDownKeyDown(){return down;}
bool Input::isLeftKeyDown(){return left;}
bool Input::isRightKeyDown(){return right;}

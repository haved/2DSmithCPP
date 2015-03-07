#include "Time.h"

#define MAX_DELTA 0.1f

static float delta = 0;

void Time::setDelta(float n_delta)
{
    delta = n_delta;
}

float Time::getDelta()
{
    return delta;
}

Uint32 prevTickMillis;
void Time::Next(Uint32 smoothing)
{
    if(SDL_GetTicks() - prevTickMillis < smoothing)
        SDL_Delay(smoothing - (SDL_GetTicks() - prevTickMillis));

    float n_delta = (SDL_GetTicks() - prevTickMillis) / 1000.0f;
    if(n_delta < MAX_DELTA)
        delta = n_delta;
    prevTickMillis = SDL_GetTicks();
}

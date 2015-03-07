#ifndef TIME_H
#define TIME_H

#include <SDL2/SDL.h>

class Time
{
    public:
        static void Next(Uint32 smoothing);
        static void setDelta(float delta);
        static float getDelta();
    protected:
    private:
};

#endif // TIME_H

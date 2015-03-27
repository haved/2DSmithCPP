#ifndef RENDERHELPER_H
#define RENDERHELPER_H

#include "Texture.h"

class RenderHelper
{
    public:
        static void ResetColor();
        static void FillRectangleWithTexture(float x, float y, float x2, float y2, Texture* t);
        static void FillRectangleWithTexture(float x, float y, float x2, float y2, Texture* t, float z);
        static void FillRectangleWithTexture(float x, float y, float x2, float y2, float texX1, float texY1, float texX2, float texY2, Texture* t);
        static void FillRectangleWithTexture(float x, float y, float x2, float y2, float texX1, float texY1, float texX2, float texY2, Texture* t, float z);
        static void EnableTextures();
        static void DisableTextures();
    protected:
    private:
};

#endif // RENDERHELPER_H

#include "RenderHelper.h"
#include <GL/gl.h>

bool colorReset = false;
void RenderHelper::ResetColor()
{
    if(colorReset)
        return;
    glColor3f(1.0f,1.0f,1.0f);
    colorReset = true;
}

void RenderHelper::FillRectangleWithTexture(float x, float y, float x2, float y2, float texX1, float texY1, float texX2, float texY2, Texture* t)
{
    t->Bind();
    EnableTextures();
    glBegin(GL_QUADS);
    glTexCoord2f(texX1, texY1);
    glVertex2f(x, y);
    glTexCoord2f(texX1, texY2);
    glVertex2f(x, y2);
    glTexCoord2f(texX2, texY2);
    glVertex2f(x2, y2);
    glTexCoord2f(texX2, texY1);
    glVertex2f(x2, y);
    glEnd();
}

void RenderHelper::FillRectangleWithTexture(float x, float y, float x2, float y2, Texture* t)
{
    t->Bind();
    EnableTextures();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex2f(x, y);
    glTexCoord2f(0, 1);
    glVertex2f(x, y2);
    glTexCoord2f(1, 1);
    glVertex2f(x2, y2);
    glTexCoord2f(1, 0);
    glVertex2f(x2, y);
    glEnd();
}

bool texEnabled = false;
void RenderHelper::EnableTextures()
{
    if(!texEnabled)
    {
        glEnable(GL_TEXTURE_2D);
        texEnabled = true;
    }
}

void RenderHelper::DisableTextures()
{
    if(texEnabled)
    {
        glDisable(GL_TEXTURE_2D);
        texEnabled = false;
    }
}

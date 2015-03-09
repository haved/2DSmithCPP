#include "PlayerEntity.h"
#include "Engine.h"
#include "Time.h"
#include "RenderHelper.h"
#include <iostream>
#include <GL/gl.h>

#define SPEED 800
#define FRICTION 8

PlayerEntity::PlayerEntity(float x, float y, float left, float right, float up, float down)
{
    this->x = x;
    this->y = y;
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
}

PlayerEntity::~PlayerEntity()
{
    std::cout << "PlayerEntity was destructed" << std::endl;
}

Vector2f accel;

void PlayerEntity::Update(Scene* s)
{
    accel.xy(0,0);

    if(Input::isLeftKeyDown())
        accel.x-=1;
    if(Input::isRightKeyDown())
        accel.x+=1;
    if(Input::isUpKeyDown())
        accel.y-=1;
    if(Input::isDownKeyDown())
        accel.y+=1;

    if(!accel.IsNull())
    {
        accel.Normalize();
        accel.Multiply(SPEED*Time::getDelta());

        speed.Add(accel);
    }

    if(!speed.IsNull())
    {
        float l = speed.GetLength();
        l -= l * FRICTION * Time::getDelta();
        speed.Normalize();
        speed.Multiply(l);
    }

    MoveAsSolid(s);
}

void PlayerEntity::Render(Scene* s)
{
    RenderHelper::DisableTextures();
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0.3f, 0.6f);
    glVertex2f(x, y-up);
    glColor3f(0.6f, 1, 0.3f);
    glVertex2f(x-left, y+down);
    glColor3f(0.3f, 0.6f, 1);
    glVertex2f(x+right, y+down);
    glEnd();
}

#include "PlayerEntity.h"
#include "Engine.h"
#include "Time.h"
#include "RenderHelper.h"
#include <iostream>
#include <GL/gl.h>
#include <cmath>

#define SPEED 1500
#define FRICTION 8

#define DOWN 0
#define RIGHT 2
#define LEFT 1
#define UP 3

#define ANIM_FRAME_AMOUNT 3
#define SUB_ANIM_FRAM_MAX 1500
int direction = 0;
int animFrame = 0;
float subAnimFrame = 0;
PlayerEntity::PlayerEntity(float x, float y, float width, float height, std::shared_ptr<Texture> texture)
{
    this->x = x;
    this->y = y;
    this->up = height/2;
    this->down = up;
    this->left = width/2;
    this->right = left;
    this->texture = texture;
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
        l -= l * (accel.IsNull() ? 2 : 1) *FRICTION * Time::getDelta();
        speed.Normalize();
        if(speed.y > 0.5)
            direction=DOWN;
        else if(speed.y < -0.5)
            direction=UP;
        else if(speed.x > 0)
            direction=RIGHT;
        else if(speed.x < 0)
            direction=LEFT;
        speed.Multiply(l);
    }

    MoveAsSolid(s);
    subAnimFrame += speed.GetLength();
    while(subAnimFrame > SUB_ANIM_FRAM_MAX)
    {
        subAnimFrame -= SUB_ANIM_FRAM_MAX;
        animFrame++;
    }
    while(animFrame > ANIM_FRAME_AMOUNT)
        animFrame -= ANIM_FRAME_AMOUNT;
}

void PlayerEntity::Render(Scene* s)
{
    RenderHelper::ResetColor();
    float x1 = ((int)animFrame)/(float)ANIM_FRAME_AMOUNT;
    float y1 = direction / 4.0f;
    RenderHelper::FillRectangleWithTexture(x-left-4, y-up, x+right+4, y+down, x1, y1, x1+1.0f/ANIM_FRAME_AMOUNT, y1+1.0f/4, texture.get());
}

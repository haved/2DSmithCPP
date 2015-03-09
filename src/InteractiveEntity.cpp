#include "InteractiveEntity.h"

#include "RenderHelper.h"

InteractiveEntity::InteractiveEntity(float x, float y, float left, float right, float up, float down, std::shared_ptr<Texture> t)
{
    this->x=x;
    this->y=y;
    this->left=left;
    this->right=right;
    this->up=up;
    this->down=down;
    this->texture=t;
}

InteractiveEntity::~InteractiveEntity(){}

void InteractiveEntity::Update(Scene* s){}

void InteractiveEntity::Render(Scene* s)
{
    RenderHelper::ResetColor();
    RenderHelper::FillRectangleWithTexture(x-left, y-up, x+right, y+down, texture.get());
}

Collider* InteractiveEntity::GetCollider()
{
    return this;
}

float InteractiveEntity::getX1() {return x-left;}

float InteractiveEntity::getX2() {return x+right;}

float InteractiveEntity::getY1() {return y-up;}

float InteractiveEntity::getY2() {return y+down;}

bool InteractiveEntity::isSolid() {return true;}

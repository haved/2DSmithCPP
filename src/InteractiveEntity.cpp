#include "InteractiveEntity.h"

#include "RenderHelper.h"
#include "Scene.h"

InteractiveEntity::InteractiveEntity(float x, float y, float left,
float right, float up, float down, std::shared_ptr<Texture> t) : InteractiveEntity(x, y, left, right, up, down, up, t){}

InteractiveEntity::InteractiveEntity(float x, float y, float left,
float right, float up, float down, float height, std::shared_ptr<Texture> t)
{
    this->x=x;
    this->y=y;
    this->left=left;
    this->right=right;
    this->up=up;
    this->down=down;
    this->texture=t;
    this->height=height;
}

InteractiveEntity::~InteractiveEntity(){}

void InteractiveEntity::Update(Scene* s){}

void InteractiveEntity::Render(Scene* s)
{
    RenderHelper::ResetColor();
    RenderHelper::FillRectangleWithTexture(x-left, y-height, x+right, y+down, texture.get(), y/s->getHeight());
}

bool InteractiveEntity::isSolid()
{
    return true;
}

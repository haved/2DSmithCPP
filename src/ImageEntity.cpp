#include "ImageEntity.h"

#include "RenderHelper.h"

ImageEntity::ImageEntity(float x, float y, float x2, float y2, float texX, float texY, float texX2, float texY2, std::shared_ptr<Texture> t)
{
    this->x=x;
    this->y=y;
    this->left=0;
    this->right=x2-x;
    this->up=0;
    this->down=y2-y;
    this->texX=texX;
    this->texY=texY;
    this->texX2=texX2;
    this->texY2=texY2;
    this->texture=t;
}

ImageEntity::~ImageEntity(){}

void ImageEntity::Render(Scene* s)
{
    RenderHelper::ResetColor();
    RenderHelper::FillRectangleWithTexture(x, y, x+right, y+down, texX, texY, texX2, texY2, texture.get());
}

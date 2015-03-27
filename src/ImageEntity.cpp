#include "ImageEntity.h"

#include "RenderHelper.h"

ImageEntity::ImageEntity(float x, float y, float x2, float y2,
float texX, float texY, float texX2, float texY2, std::shared_ptr<Texture> t) : ImageEntity(x, y, x2, y2, texX, texY, texX2, texY2, false, t){}

ImageEntity::ImageEntity(float x1, float y1, float x2, float y2,
float texX, float texY, float texX2, float texY2, bool solid, std::shared_ptr<Texture> t)
{
    this->x=(x1+x2)/2;
    this->y=(y1+y2)/2;
    this->left=(x2-x1)/2;
    this->right=left;
    this->up=(y2-y1)/2;
    this->down=up;
    this->texX=texX;
    this->texY=texY;
    this->texX2=texX2;
    this->texY2=texY2;
    this->texture=t;
    this->solid=solid;
}

ImageEntity::~ImageEntity(){}

void ImageEntity::Render(Scene* s)
{
    RenderHelper::ResetColor();
    RenderHelper::FillRectangleWithTexture(x-left, y-up, x+right, y+down, texX, texY, texX2, texY2, texture.get());
}

bool ImageEntity::isSolid()
{
    return solid;
}

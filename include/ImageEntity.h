#ifndef IMAGEEENTITY_H
#define IMAGEEENTITY_H

#include "Entity.h"
#include "Texture.h"
#include <memory>

class ImageEntity : public Entity
{
    public:
        ImageEntity(float x, float y, float x2, float y2,
            float texX, float texY, float texX2, float texY2, std::shared_ptr<Texture> t);
        ImageEntity(float x, float y, float x2, float y2,
            float texX, float texY, float texX2, float texY2, bool solid, std::shared_ptr<Texture> t);
        virtual ~ImageEntity();
        void Render(Scene* scene) override;
    protected:
        bool isSolid() override;
    private:
        std::shared_ptr<Texture> texture;
        float texX = 0, texY = 0, texX2 = 0, texY2 = 0;
        bool solid=false;
};

#endif //IMAGEEENTITY_H

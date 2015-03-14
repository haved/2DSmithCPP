#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include "Entity.h"
#include "Texture.h"
#include <memory>

class PlayerEntity : public Entity
{
    public:
        PlayerEntity(float x, float y, float xSize, float zSize, float height, std::shared_ptr<Texture> texture);
        virtual ~PlayerEntity();
        void Update(Scene* s) override;
        void Render(Scene* s) override;
        bool isSolid() override;
    protected:
    private:
        std::shared_ptr<Texture> texture;
        float height;
};

#endif // PLAYERENTITY_H

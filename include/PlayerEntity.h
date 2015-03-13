#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include "ColliderEntity.h"
#include "Texture.h"
#include <memory>

class PlayerEntity : public ColliderEntity
{
    public:
        PlayerEntity(float x, float y, float width, float height, std::shared_ptr<Texture> texture);
        virtual ~PlayerEntity();
        void Update(Scene* s) override;
        void Render(Scene* s) override;
    protected:
    private:
        std::shared_ptr<Texture> texture;
};

#endif // PLAYERENTITY_H

#ifndef INTERACTIVEENTITY_H
#define INTERACTIVEENTITY_H

#include "Entity.h"
#include "Collider.h"
#include "Texture.h"
#include <memory>

class InteractiveEntity : public Entity, public Collider
{
    public:
        InteractiveEntity(float x, float y, float left, float right, float up, float down, std::shared_ptr<Texture> t);
        virtual ~InteractiveEntity();
        void Update(Scene* scene) override;
        void Render(Scene* scene) override;
        Collider* GetCollider() override;
        float getX1() override;
        float getX2() override;
        float getY1() override;
        float getY2() override;
        bool isSolid() override;
    private:
        std::shared_ptr<Texture> texture;
};

#endif //INTERACTIVEENTITY_H

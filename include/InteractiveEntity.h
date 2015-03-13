#ifndef INTERACTIVEENTITY_H
#define INTERACTIVEENTITY_H

#include "ColliderEntity.h"
#include "Texture.h"
#include <memory>

class InteractiveEntity : public ColliderEntity
{
    public:
        InteractiveEntity(float x, float y, float left, float right, float up, float down, std::shared_ptr<Texture> t);
        virtual ~InteractiveEntity();
        void Update(Scene* scene) override;
        void Render(Scene* scene) override;
    private:
        std::shared_ptr<Texture> texture;
};

#endif //INTERACTIVEENTITY_H

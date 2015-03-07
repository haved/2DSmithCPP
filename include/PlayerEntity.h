#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include "Entity.h"

class PlayerEntity : public Entity
{
    public:
        PlayerEntity(float x, float y, float left, float right, float up, float down);
        virtual ~PlayerEntity();
        void Update(Scene* s) override;
        void Render(Scene* s) override;
    protected:
    private:
};

#endif // PLAYERENTITY_H

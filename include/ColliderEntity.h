#ifndef COLLIDERENTITY_H
#define COLLIDERENTITY_H

#include "Entity.h"
#include "Collider.h"

class ColliderEntity : public Entity, public Collider
{
    public:
        Collider* GetCollider() override;
        float getX1() override;
        float getX2() override;
        float getY1() override;
        float getY2() override;
        bool isSolid() override;
    protected:
    private:
};

#endif // COLLIDERENTITY_H

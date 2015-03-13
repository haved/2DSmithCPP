#ifndef ENTITY_H
#define ENTITY_H
#include "Vector2f.h"
#include "Collider.h"

class Scene;

class Entity
{
    public:
        Entity();
        virtual ~Entity();
        virtual void Update(Scene* s);
        virtual void Render(Scene* s);
        virtual Collider* GetCollider();
        bool isDead();
        void Kill();
    protected:
        float x=0,y=0,left=0,right=0,up=0,down=0;
        Vector2f speed;
        bool dead = false;

        void MoveAsGhost();
        virtual void MoveAsSolid(Scene* s);
    private:
};

#endif // ENTITY_H

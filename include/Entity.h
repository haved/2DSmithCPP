#ifndef ENTITY_H
#define ENTITY_H
#include "Vector2f.h"

class Scene;

class Entity
{
    public:
        Entity();
        virtual ~Entity();
        virtual void Update(Scene* s);
        virtual void Render(Scene* s);
        bool isDead();
        void Kill();

        virtual float getSolidX1();
        virtual float getSolidX2();
        virtual float getSolidY1();
        virtual float getSolidY2();
        virtual bool isSolid();
    protected:
        float x=0,y=0,left=0,right=0,up=0,down=0;
        Vector2f speed;
        bool dead = false;

        void MoveAsGhost();
        virtual void MoveAsSolid(Scene* s);
    private:
};

#endif // ENTITY_H

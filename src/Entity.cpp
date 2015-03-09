#include "Entity.h"
#include "Scene.h"
#include "Time.h"

Entity::Entity(){}

Entity::~Entity(){}

void Entity::Update(Scene* s){}

void Entity::Render(Scene* s){}

void Entity::MoveAsGhost()
{
    x += speed.x * Time::getDelta();
    y += speed.y * Time::getDelta();
}

void Entity::MoveAsSolid(Scene* s)
{
    float newX = x + speed.x * Time::getDelta();
    float newY = y + speed.y * Time::getDelta();

    Entity* e;

    for(int i = 0; i < s->GetEntityAmount(); i++)
    {
        e = s->GetEntityAt(i);
        if((e->GetCollider()!=NULL) & (e != this))
        {
            if((newX+right > e->GetCollider()->getX1()) & (newX+right < e->GetCollider()->getX2())
             & (y - up < e->GetCollider()->getY2()) & (y + down > e->GetCollider()->getY1()))
                newX = e->GetCollider()->getX1()-right;

            if((newY+down > e->GetCollider()->getY1()) & (newY+down < e->GetCollider()->getY2())
             & (x - left < e->GetCollider()->getX2()) & (x + right > e->GetCollider()->getX1()))
                newY = e->GetCollider()->getY1()-down;

            if((newX-left < e->GetCollider()->getX2()) & (newX-left > e->GetCollider()->getX1())
             & (y - up < e->GetCollider()->getY2()) & (y + down > e->GetCollider()->getY1()))
                newX = e->GetCollider()->getX2()+left;

            if((newY-up < e->GetCollider()->getY2()) & (newY-up > e->GetCollider()->getY1())
             & (x - left < e->GetCollider()->getX2()) & (x + right > e->GetCollider()->getX1()))
                newY = e->GetCollider()->getY2()+up;
        }
    }

    x = newX;
    y = newY;
}

Collider* Entity::GetCollider()
{
    return NULL;
}

void Entity::Kill()
{
    dead = true;
}

bool Entity::isDead()
{
    return dead;
}

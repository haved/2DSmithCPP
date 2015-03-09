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
        if(e->GetCollider())
        {
            //TODO: Collision stuff!
        }
    }
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

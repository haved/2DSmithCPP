#include "Entity.h"

Entity::Entity(){}

Entity::~Entity(){}

void Entity::Update(Scene* s){}

void Entity::Render(Scene* s){}

void Entity::kill()
{
    dead = true;
}

bool Entity::isDead()
{
    return dead;
}

#include "Entity.h"
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

void Entity::Kill()
{
    dead = true;
}

bool Entity::isDead()
{
    return dead;
}

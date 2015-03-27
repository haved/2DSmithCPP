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
    float xMove = speed.x * Time::getDelta();
    float yMove = speed.y * Time::getDelta();

    Entity* e;

    for(int i = 0; i < s->GetEntityAmount(); i++)
    {
        e = s->GetEntityAt(i);
        if(e->isSolid() & (e != this))
        {
            if((getSolidX2()+xMove > e->getSolidX1()) & (getSolidX2()+xMove < e->getSolidX2())
             & (getSolidY1() < e->getSolidY2()) & (getSolidY2() > e->getSolidY1()))
                xMove = e->getSolidX1()-getSolidX2();

            if((getSolidY2()+yMove > e->getSolidY1()) & (getSolidY2()+yMove < e->getSolidY2())
             & (getSolidX1() < e->getSolidX2()) & (getSolidX2() > e->getSolidX1()))
                yMove = e->getSolidY1()-getSolidY2();

            if((getSolidX1()+xMove < e->getSolidX2()) & (getSolidX1()+xMove > e->getSolidX1())
             & (getSolidY1() < e->getSolidY2()) & (getSolidY2() > e->getSolidY1()))
                xMove = e->getSolidX2()-getSolidX1();

            if((getSolidY1()+yMove < e->getSolidY2()) & (getSolidY1()+yMove > e->getSolidY1())
             & (getSolidX1() < e->getSolidX2()) & (getSolidX2() > e->getSolidX1()))
                yMove = e->getSolidY2()-getSolidY1();
        }
    }

    x += xMove;
    y += yMove;
}

float Entity::getSolidX1() {return x-left;}

float Entity::getSolidX2() {return x+right;}

float Entity::getSolidY1() {return y-up;}

float Entity::getSolidY2() {return y+down;}

bool Entity::isSolid() {return false;}

void Entity::Kill()
{
    dead = true;
}

bool Entity::isDead()
{
    return dead;
}

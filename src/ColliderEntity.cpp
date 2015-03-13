#include "ColliderEntity.h"

Collider* ColliderEntity::GetCollider()
{
    return this;
}

float ColliderEntity::getX1() {return x-left;}

float ColliderEntity::getX2() {return x+right;}

float ColliderEntity::getY1() {return y-up;}

float ColliderEntity::getY2() {return y+down;}

bool ColliderEntity::isSolid() {return true;}

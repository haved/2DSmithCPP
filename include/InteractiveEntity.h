#ifndef INTERACTIVEENTITY_H
#define INTERACTIVEENTITY_H

#include "Entity.h"

class InteractiveEntity : public Entity
{
	InteractiveEntity();
	virtual ~InteractiveEntity();
	void Update(Scene* scene) override;
	void Render(Scene* scene) override;
};

#endif //INTERACTIVEENTITY_H
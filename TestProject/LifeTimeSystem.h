#pragma once
#include "System.h"
#include "Entity.h"
#include "Time.h"

class LifetimeSystem : public System
{
	bool condition(Handle<Entity> i)
	{
		return i->lifecycle > -1;
	}
	void update(Handle<Entity> i)
	{
		if (i->lifecycle->lifetime > i->lifecycle->lifespan)
			Entity::free(i);
		else
			i->lifecycle->lifetime += Time::instance().getDeltaTime();
	}
};
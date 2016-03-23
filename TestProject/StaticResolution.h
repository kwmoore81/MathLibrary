#pragma once
#include "CollisionDetection.h"

namespace kml
{
	class StaticResolution : public CollisionSystem
	{
		bool condition(Collision c)
		{
			return c.first->rigidbody > -1 && c.second->rigidbody < 0 ||
				c.first->rigidbody <  0 && c.second->rigidbody > -1;
		}

		void update(Collision c)
		{
			Handle<Entity> t;
			//TODO add static equation
		}
	};
}
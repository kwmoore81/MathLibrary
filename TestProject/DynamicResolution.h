#pragma once
#include "kmath.h"
#include "CollisionDetection.h"

namespace kml
{
	class DynamicResolution : public CollisionSystem
	{
		bool condition(Collision c)
		{
			return c.first->rigidbody > -1 && c.second->rigidbody > -1;
		}

		void update(Collision c)
		{
			vec2 MTV = c.collision.CollisionNormal * c.collision.PenetrationDepth;

			vec2 p1 = c.first->transform->getpos() - MTV / 2;
			vec2 p2 = c.second->transform->getpos() + MTV / 2;

			c.first->transform->setPos(p1);
			c.second->transform->setPos(p2);

			std::swap(c.first->rigidbody->velocity, c.second->rigidbody->velocity);
		}
	};
}

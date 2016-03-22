#pragma once
#include "System.h"
#include "Input.h"
#include "Time.h"
#include "Factory.h"

namespace kml
{
	class PlayerFlightSystem : public System
	{
		bool condition(Handle<Entity> i)
		{
			return i->rigidbody > -1 &&
				i->transform > -1 &&
				i->controller > -1;
		}

		void update(Handle<Entity> i)
		{
			auto  &input = Input::instance();
			auto  &c = *i->controller;
			auto  &r = *i->rigidbody;
			float dt = Time::instance().getDeltaTime();

			/*if (input.getKey(c.LEFT))
				i->rigidbody->addTorque(c.turnSpeed);

			if (input.getKey(c.RIGHT))
				r.addTorque(-c.turnSpeed);*/
			
			if (input.getKey(c.LEFT))
				r.addForce(i->transform->getRight() * -c.speed);

			if (input.getKey(c.RIGHT))
				r.addForce(i->transform->getRight() * c.speed);

			if (input.getKey(c.FORWARD))
				r.addForce(i->transform->getUp() * c.speed);
			
			if (input.getKey(c.DOWN))
				r.addForce(i->transform->getUp() * -c.speed);
			
				if (input.getKey(' '))
			{
				Factory::makeBullet(i->transform->getpos(), i->transform->getUp());
			}
		}

	};
}
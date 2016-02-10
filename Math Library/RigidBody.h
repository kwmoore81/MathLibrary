#pragma once
#include "kmath.h"
namespace kml
{
	class Rigidbody
	{
	public:
		float mass;

		vec2 velocity, acceleration, force, jerk;
		float drag;

		float angularVelocity, angularAcceleration, torque, angularJerk;
		float angularDrag;

		Rigidbody();
		void addForce(const vec2 &);
		void addTorque(float);

		void integrate(class Transform *, float dt);
	};
}
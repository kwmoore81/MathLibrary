#pragma once
#include "Math.h"
#include "transform.h"

class RigidBody
{
public:
	//F = ma
	//a +=F/m
	vec2 velocity, acceleration, force;
	float mass, drag;
	
	float angularVelocity, angularAcceleration, torque;
	float angularDrag;

	RigidBody();
	void addForce(const vec2 &);
	//void addTorque(float);
	void addTorque(const vec2 &);
	void intergrate(Transform *, float dt);
};
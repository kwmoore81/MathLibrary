#include "RigidBody.h"

using namespace kml;

RigidBody::RigidBody():
	acceleration({ 0,0 }), velocity({ 0,0 }), mass(1), drag()
{

}

void RigidBody::addForce(const vec2 &a)
{
	force = force + a;
}

void RigidBody::addTorque(const vec2 &)
{

}

void RigidBody::intergrate(Transform *t, float dt)
{
	acceleration = force / mass;
	velocity = velocity = acceleration*dt;
	t->setPos(t->getpos() + velocity*dt);

	velocity = velocity - velocity * drag * dt;

	force = { 0,0 };
}

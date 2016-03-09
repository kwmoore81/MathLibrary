#pragma once
#include "Entity.h"
// Factory Method
// Constructor with a lot of meaningful defaults

struct Factory
{

	static Handle<Entity> makeBall(vec2 pos, vec2 vel, float radius, float mass)
	{
		auto e = Entity::make();
		e->collider = Collider::make();
		e->rigidbody = Rigidbody::make();
		e->transform = Transform::make();

		e->collider->circle.radius = radius;
		e->collider->shape = Collider::e_CIRCLE;
		e->rigidbody->mass = mass;
		e->rigidbody->velocity = vel;
		e->transform->setPosition(pos);
		return e;
	}

	static Handle<Entity> makeWall(vec2 pos, vec2 normal)
	{
		auto e = Entity::make();
		e->collider = Collider::make();
		e->transform = Transform::make();

		e->collider->plane.normal = normal;
		e->collider->shape = Collider::e_PLANE;
		e->transform->setPosition(pos);

		return e;
	}

};
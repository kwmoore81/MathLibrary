#pragma once
#include "Entity.h"

// Factory Method
// Constructor with a lot of meaningful defaults

namespace kml
{
	struct Factory
	{

		static Handle<Entity> makeBall(vec2 pos, vec2 vel, float radius, float mass)
		{
			auto e = Entity::make();
			e->collider = Collider::make();
			e->rigidbody = Rigidbody::make();
			e->transform = Transform::make();
			e->sprite = Sprite::make();

			e->sprite->assetName = "Slime";
			e->sprite->dimension = vec2{ 72,72 };

			e->collider->circle.r = radius+10;
			e->collider->shape = Collider::e_CIRCLE;
			e->rigidbody->mass = mass;
			e->rigidbody->velocity = vel;
			e->transform->setPos(pos);
			return e;
		}

		static Handle<Entity> makeWall(vec2 pos, vec2 normal)
		{
			auto e = Entity::make();
			e->collider = Collider::make();
			e->rigidbody = Rigidbody::make();
			e->transform = Transform::make();

			e->collider->aabb.halfextents = { 60,80 };
			e->collider->shape = Collider::e_AABB;
			e->transform->setPos(pos);

			return e;
		}

		static Handle<Entity> makePlayer(vec2 pos)
		{
			auto e = Entity::make();
			e->collider = Collider::make();
			e->rigidbody = Rigidbody::make();
			e->transform = Transform::make();
			e->controller = PlayerController::make();
			e->sprite = Sprite::make();

			e->sprite->assetName = "Slime";
			e->sprite->dimension = vec2{ 72,72 };

			e->collider->shape = Collider::e_CIRCLE;
			e->collider->circle.r = 30;
			e->transform->setPos(pos);

			return e;
		}


		static Handle<Entity> makeBullet(vec2 pos, vec2 dir, float life = 1.6f, float speed = 100.f)
		{
			auto e = Entity::make();
			e->rigidbody = Rigidbody::make();
			e->transform = Transform::make();
			e->lifecycle = Lifecycle::make();

			e->transform->setPos(pos);
			e->rigidbody->velocity = dir * speed;
			e->lifecycle->lifespan = life;

			e->transform->setAngle(perp(dir).angle());

			return e;
		}
	};
}
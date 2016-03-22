#pragma once
#include "GCData.h"

#include "collider.h"
#include "Rigidbody.h"
#include "transform.h"
#include "Lifespan.h"
#include "PlayerController.h"
#include "Sprite.h"

namespace kml
{
	struct Entity : public GCData<Entity>
	{
		// Name
		// Tag
		// Active
		// TypeID

		Handle<Transform> transform;
		Handle<Rigidbody> rigidbody;
		Handle<Lifecycle> lifecycle;
		Handle<Collider > collider;
		Handle<PlayerController> controller;
		Handle<Sprite> sprite;

		void onFree()
		{
			Transform::free(transform.index);
			Rigidbody::free(rigidbody.index);
			Lifecycle::free(lifecycle.index);
			Collider::free(collider.index);
			PlayerController::free(controller.index);
			Sprite::free(sprite.index);
		}
	};
}

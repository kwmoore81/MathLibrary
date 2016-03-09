#pragma once
#include "GCData.h"

#include "collider.h"
#include "Rigidbody.h"
#include "transform.h"

struct Entity : GCData<Entity>
{
	// Name
	// Tag
	// Active
	// TypeID

	Handle<Transform> transform;
	Handle<Rigidbody> rigidbody;
	Handle<Collider > collider;

	void onFree()
	{
		Transform::free(transform.index);
		Rigidbody::free(rigidbody.index);
		Collider::free(collider.index);
	}
};
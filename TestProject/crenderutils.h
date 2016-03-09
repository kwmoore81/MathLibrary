#pragma once
#include "kmath.h"
#include "shapes.h"
#include "transform.h"
#include "Rigidbody.h"
#include "collider.h"

namespace kml
{
	void drawMatrix(const mat3 &);
	void drawVector(const mat3 &, const vec2 &, unsigned TINT = 0x00ffffff);
	void drawPlane(const Plane   &, unsigned TINT);
	void drawAABB(const AABB    &, unsigned TINT);
	void drawCircle(const Circle  &, unsigned TINT);
	void drawRay(const Ray     &, unsigned TINT);


	void drawTransform(const Transform &);
	void drawRigidbody(const Transform &, const Rigidbody &);
	void drawCollider(const Transform &, const Collider  &);
}
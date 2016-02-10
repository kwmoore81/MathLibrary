#pragma once
#include "vec2.h"
#include "mat3.h"
#include <vector>


//Different shapes of varying utility.

// note that this isn't guaranteed to be a convex hull- needs an
// algorithm to test it.

namespace kml
{
	struct ConvexHull { std::vector<vec2> verts; };
	struct Ray { vec2 position, direction; float length; };
	struct Plane { vec2 position, normal; };
	struct Circle { vec2 position; float r; };
	struct AABB { vec2 position, halfextents;
	              vec2 min() const, max() const; };

	inline vec2 AABB::min() const { return position - halfextents; }
	inline vec2 AABB::max() const { return position + halfextents; }


	//Useful for taking a gameobject's transform and applying it
	// to a shape for collision detection
	AABB        operator*(const mat3 &m, const AABB      &a);
	Circle      operator*(const mat3 &m, const Circle     &a);
	Ray         operator*(const mat3 &m, const Ray        &a);
	Plane       operator*(const mat3 &m, const Plane      &a);
	ConvexHull  operator*(const mat3 &m, const ConvexHull &a);
}
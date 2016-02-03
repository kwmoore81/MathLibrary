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
	struct ray { vec2 position, direction; float length; };
	struct plane { vec2 position, normal; };
	struct circle { vec2 position; float r; };
	struct aabb { vec2 position, halfextents, min(), max(); };


	//Useful for taking a gameobject's transform and applying it
	// to a shape for collision detection
	aabb        operator*(const mat3 &m, const aabb       &a);
	circle      operator*(const mat3 &m, const circle     &a);
	ray         operator*(const mat3 &m, const ray        &a);
	plane       operator*(const mat3 &m, const plane      &a);
	ConvexHull  operator*(const mat3 &m, const ConvexHull &a);
}
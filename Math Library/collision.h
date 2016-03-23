#pragma once
#include "shapes.h"
#include "kmath.h"



namespace kml
{
	struct CollisionData // Wrapper for Minimum Translation Vector
	{
		bool  isOverlap;
		float PenetrationDepth;
		vec2  CollisionNormal; // CollisionNormal * PenetrationDepth = Minimum Translation Vector, also called the impulse vector, very important! 
		vec2  PointOfContact; // optional.
	};

	// Some distance formula
	float point_plane_dist(const vec2 &a, const Plane &b);
	float ray_plane_dist(const Ray  &a, const Plane &b);

	// SAT algorithm!
	CollisionData sat_hull(const ConvexHull &A, const ConvexHull &B);

	//// optimized edge-cases
	//CollisionData sat_hull_circle(const ConvexHull &A, const Circle     &b); // use radius in all axes of convex hull
	//CollisionData sat_hull_ray(const ConvexHull &A, const Ray        &b); // combination of circle and plane algorithms, freebie
	//CollisionData sat_hull_plane(const ConvexHull &A, const Plane      &b); // only axis is the plane
	//CollisionData sat_hull_AABB(const ConvexHull &A, const AABB       &b); // aabb only contributes 2 axes


	//																	   // determine whether or not the shapes are overlapping... fast!
	//bool iTest_aabb(const AABB   &a, const AABB   &b);
	//bool iTest_aabb_circle(const AABB   &a, const Circle &b);
	//bool iTest_aabb_plane(const AABB   &a, const Plane  &b);
	//bool iTest_aabb_ray(const AABB   &a, const Ray	   &b);
	//bool iTest_circle(const Circle &a, const Circle &b);
	//bool iTest_circle_plane(const Circle &a, const Plane  &b);
	//bool iTest_circle_ray(const Circle &a, const Ray    &b);
	//bool iTest_ray_plane(const Ray    &a, const Plane  &b);


	//// Calculate the Minimum Translation Vector
	//// same algorithms as the fast ones, but we're fetching more data
	//CollisionData mtv_aabb(const AABB   &a, const AABB   &b);
	//CollisionData mtv_aabb_circle(const AABB   &a, const Circle &b);
	//CollisionData mtv_aabb_plane(const AABB   &a, const Plane  &b);
	//CollisionData mtv_aabb_ray(const AABB   &a, const Ray    &b);
	//CollisionData mtv_circle(const Circle &a, const Circle &b);
	//CollisionData mtv_circle_plane(const Circle &a, const Plane  &b);
	//CollisionData mtv_circle_ray(const Circle  &a, const Ray    &b);
	//CollisionData mtv_ray_plane(const Ray     &a, const Plane  &b);


	// All of the basic tests
	CollisionData iTest(const AABB   &a, const AABB   &b);
	CollisionData iTest(Circle a, const AABB &b);
	CollisionData iTest(const AABB   &a, const Ray    &b);
	CollisionData iTest(const AABB   &a, const Plane  &b);

	CollisionData iTest(const Circle &a, const Circle &b);
	CollisionData iTest(const Circle &a, const Plane  &b);
	CollisionData iTest(const Circle &a, const Ray    &b);

	CollisionData iTest(const Ray    &a, const Plane  &b);


	// Convex Hull vs remaining shapes
	CollisionData iTest(const ConvexHull &A, const ConvexHull &B);
	CollisionData iTest(const ConvexHull &A, const Circle     &b);
	CollisionData iTest(const ConvexHull &A, const Ray        &b);
	CollisionData iTest(const ConvexHull &A, const Plane      &b);
	CollisionData iTest(const ConvexHull &A, const AABB       &b);



	// flip overloads for lhs/rhs
	//inline CollisionData iTest(const Circle &b, const AABB   &a) { return iTest(a, b); }
	inline CollisionData iTest(const Plane  &b, const AABB   &a) { return iTest(a, b); }
	inline CollisionData iTest(const Ray    &b, const AABB   &a) { return iTest(a, b); }

	inline CollisionData iTest(const Plane  &b, const Circle &a) { return iTest(a, b); }
	inline CollisionData iTest(const Ray    &b, const Circle &a) { return iTest(a, b); }

	inline CollisionData iTest(const Plane  &b, const Ray    &a) { return iTest(a, b); }

	inline CollisionData iTest(const Circle &b, const ConvexHull &A) { return iTest(A, b); }
	inline CollisionData iTest(const Ray    &b, const ConvexHull &A) { return iTest(A, b); }
	inline CollisionData iTest(const Plane  &b, const ConvexHull &A) { return iTest(A, b); }
	inline CollisionData iTest(const AABB   &b, const ConvexHull &A) { return iTest(A, b); }

}
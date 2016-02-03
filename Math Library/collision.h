#pragma once
#include "shapes.h"


struct CollisionData // Wrapper for Minimum Translation Vector
{
	bool  collides;
	float PenetrationDepth;
	vec2  CollisionNormal;
	vec2  PointOfContact;
};

// Some distance formula
float point_plane_dist(const vec2 &a, const plane &b);
float ray_plane_dist(const ray  &a, const plane &b);

// SAT algorithm!
CollisionData sat_hull(const ConvexHull &A, const ConvexHull &B);

// optimized edge-cases
CollisionData sat_hull_circle(const ConvexHull &A, const circle     &b); // use radius in all axes of convex hull
CollisionData sat_hull_ray(const ConvexHull &A, const ray        &b); // combination of circle and plane algorithms, freebie
CollisionData sat_hull_plane(const ConvexHull &A, const plane      &b); // only axis is the plane
CollisionData sat_hull_AABB(const ConvexHull &A, const aabb       &b); // aabb only contributes 2 axes


																	   // determine whether or not the shapes are overlapping... fast!
bool iTest_aabb(const aabb   &a, const aabb   &b);
bool iTest_aabb_circle(const aabb   &a, const circle &b);
bool iTest_aabb_plane(const aabb   &a, const plane  &b);
bool iTest_aabb_ray(const aabb   &a, const ray	   &b);
bool iTest_circle(const circle &a, const circle &b);
bool iTest_circle_plane(const circle &a, const plane  &b);
bool iTest_circle_ray(const circle &a, const ray    &b);
bool iTest_ray_plane(const ray    &a, const plane  &b);


// Calculate the Minimum Translation Vector
// same algorithms as the fast ones, but we're fetching more data
CollisionData mtv_aabb(const aabb   &a, const aabb   &b);
CollisionData mtv_aabb_circle(const aabb   &a, const circle &b);
CollisionData mtv_aabb_plane(const aabb   &a, const plane  &b);
CollisionData mtv_aabb_ray(const aabb   &a, const ray    &b);
CollisionData mtv_circle(const circle &a, const circle &b);
CollisionData mtv_circle_plane(const circle &a, const plane  &b);
CollisionData mtv_circle_ray(const circle  &a, const ray    &b);
CollisionData mtv_ray_plane(const ray     &a, const plane  &b);
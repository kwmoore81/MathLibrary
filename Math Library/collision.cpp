
#include <cmath>
#include <list>
#include <algorithm>
#include "collision.h"

using namespace kml;

float kml::point_plane_dist(const vec2 & a, const Plane & b)
{
	return dot(b.normal, a - b.position);
}

float kml::ray_plane_dist(const Ray & a, const Plane & b)
{
	return dot(b.normal, a.position - b.position) / -dot(b.normal, a.direction);
}

//untested - algorithm sound but could be typos
CollisionData kml::sat_hull(const ConvexHull &A, const ConvexHull &B)
{
	CollisionData cd = { false, INFINITY }; // setup return value

	std::vector<vec2> axes;
	axes.reserve(A.verts.size() + B.verts.size());

	for (int i = 0; i < A.verts.size(); ++i) {
		kml::vec2 vectorBetween = A.verts[i] - A.verts[(i + 1) % A.verts.size()];
		kml::vec2 normal = vectorBetween.normal();
		kml::vec2 perpOfNormal = perp(normal);
		axes.push_back(perpOfNormal);
		axes.push_back(perp((A.verts[i] - A.verts[(i + 1) % A.verts.size()]).normal()));
	}

	for (int i = 0; i < B.verts.size(); ++i)
	{
		kml::vec2 vectorBetween = B.verts[i] - B.verts[(i + 1) % B.verts.size()];
		kml::vec2 normal = vectorBetween.normal();
		kml::vec2 perpOfNormal = perp(normal);
		axes.push_back(perpOfNormal);
		axes.push_back(perp((B.verts[i] - B.verts[(i + 1) % B.verts.size()]).normal()));
	}
		

	for (int j = 0; j < axes.size(); ++j)
	{
		float amin = INFINITY, amax = -INFINITY;
		float bmin = INFINITY, bmax = -INFINITY;

		for (int i = 0; i < A.verts.size(); ++i)
		{
			float pp = dot(axes[j], A.verts[i]);
			amin = fminf(pp, amin);
			amax = fminf(pp, amax);
		}

		for (int i = 0; i < B.verts.size(); ++i)
		{
			float pp = dot(axes[j], B.verts[i]);
			amin = fminf(pp, amin);
			amax = fminf(pp, amax);
		}

		float pdepth = fminf(amax - bmin, bmax - amin);

		if (pdepth < cd.PenetrationDepth)
		{
			cd = { pdepth < 0, pdepth, axes[j] };
			if (pdepth < 0) return cd;
		}
	}
	return cd;
}

CollisionData kml::iTest(const AABB & a, const AABB & b)
{
	CollisionData cd;

	if(a.max().x < b.min().x || b.max().x < a.min().x || a.max().y < b.min().y || b.max().y < a.min().y)
	{
		cd.isOverlap = false;
		cd.PenetrationDepth = 0;
	}
	else
	{
		cd.isOverlap = true;

		//TODO PenetrationDepth??
	}

	return cd;
}

CollisionData kml::iTest(const AABB & a, const Circle & b)
{
	CollisionData cd;
	vec2 bc = clamp(b.position, a.min(), a.max());
	float dist = dot((b.position - bc), (b.position - bc));
	float diff = dist - (b.r * b.r);
	if  (dist < (b.r * b.r))
	{
		cd.isOverlap = true;
		cd.PenetrationDepth = diff;
		
	}
	else
	{
		cd.isOverlap = false;
		cd.PenetrationDepth = 0;
	}
	return cd;
}

CollisionData kml::iTest(const AABB & a, const Ray & b)
{
	return CollisionData();
}

CollisionData kml::iTest(const AABB & a, const Plane & b)
{
	return CollisionData();
}

CollisionData kml::iTest(const Circle & a, const Circle & b)
{
	CollisionData cd;
	if (dot((a.position - b.position), (a.position - b.position)) < (a.r*a.r) + (b.r * b.r))
	{
		cd.isOverlap = false;
		cd.PenetrationDepth = 0;
	}
	else
	{
		cd.isOverlap = true;
		cd.PenetrationDepth = (a.r*a.r) + (b.r * b.r) - (dot((a.position - b.position), (a.position - b.position)));
	}
	return cd;
}

CollisionData kml::iTest(const Circle & a, const Plane & b)
{
	return CollisionData();
}

CollisionData kml::iTest(const Circle & a, const Ray & b)
{
	return CollisionData();
}

CollisionData kml::iTest(const Ray & a, const Plane & b)
{
	return CollisionData();
}

CollisionData kml::iTest(const ConvexHull & A, const ConvexHull & B)
{
	return CollisionData();
}

CollisionData kml::iTest(const ConvexHull & A, const Circle & b)
{
	return CollisionData();
}

CollisionData kml::iTest(const ConvexHull & A, const Ray & b)
{
	return CollisionData();
}

CollisionData kml::iTest(const ConvexHull & A, const Plane & b)
{
	return CollisionData();
}

CollisionData kml::iTest(const ConvexHull & A, const AABB & b)
{
	return CollisionData();
}
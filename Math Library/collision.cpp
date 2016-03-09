
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
	CollisionData cd;
	Plane s1p1, s1p2, s2p1, s2p2;
	float t_s1p1, t_s1p2, t_s2p1, t_s2p2,tmin, tmax, tmins1, tmaxs1, tmins2, tmaxs2;
	bool s1Par, s2Par;

	s1p1.position = a.min();
	s1p2.position = a.max();
	s2p1.position = a.min();
	s2p2.position = a.max();

	s1p2.normal = vec2({ 0, -1 });
	s1p2.normal = vec2({ 0 , 1 });
	s2p1.normal = vec2({ -1, 0 });
	s2p2.normal = vec2({ 1 , 0 });

	t_s1p1 = dot(s1p1.normal, (b.position - s1p1.position)) / -dot(s1p1.normal, b.direction);
	if ( t_s1p1 != 0)
	{
		t_s1p2 = dot(s1p2.normal, (b.position - s1p2.position)) / -dot(s1p2.normal, b.direction);
		s1Par = false;
	}
	else 
	{
		s1Par = true;
	}
	
	t_s2p1 = dot(s2p1.normal, (b.position - s2p1.position)) / -dot(s2p1.normal, b.direction);
	if (t_s2p1 != 0)
	{
		t_s2p2 = dot(s2p2.normal, (b.position - s2p2.position)) / -dot(s2p2.normal, b.direction);
		s2Par = false;
	}
	else
	{
		s2Par = true;
	}
	
	if (!s1Par)
	{
		tmins1 = std::fmin(t_s1p1, t_s1p2);
		tmaxs1 = std::fmax(t_s1p1, t_s1p2);
	}

	if (!s2Par)
	{
		tmins2 = std::fmin(t_s2p1, t_s2p2);
		tmaxs2 = std::fmax(t_s2p1, t_s2p2);
	}

	if (s1Par)
	{
		tmin = tmins2;
		tmax = tmaxs2;
	}
	else if (s2Par)
	{
		tmin = tmins1;
		tmax = tmaxs1;
	}

	else
	{
		tmin = std::fmax(tmins1, tmins2);
		tmax = std::min(tmaxs1, tmaxs2);
	}

	cd.isOverlap = tmin <= tmax && 0 <= tmin <= b.length;
	if (cd.isOverlap == false) { cd.PenetrationDepth = 0; };
	//TODO Penetration Depth? CollisionNormal?
	return cd;
}

CollisionData kml::iTest(const AABB & a, const Plane & b)
{
	CollisionData cd;
	
	cd.isOverlap = dot(b.normal, (a.position - b.position)) <= a.halfextents.x * fabs(dot(b.normal, vec2({ 1,0 }))) + a.halfextents.y * fabs(dot(b.normal, vec2({ 0,1 })));
	if (cd.isOverlap == false) { cd.PenetrationDepth = 0;};
	//TODO Penetration Depth? Collision Normal?
	return cd;
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
	CollisionData cd;
	
	cd.isOverlap = dot(b.normal, (a.position - b.position)) <= a.r;
	cd.PenetrationDepth = (a.r*a.r) - (dot((a.position - b.position), (a.position - b.position)));
	
	//TODO CollisionNormal?
	
	return cd;
}

CollisionData kml::iTest(const Circle & a, const Ray & b)
{
	CollisionData cd;
	
	float fClamp = std::fmin(b.length, std::fmax(dot((a.position - b.position),b.direction),0));
	vec2 pc = b.position + b.direction * fClamp;
	cd.isOverlap = dot((a.position - pc), (a.position - pc)) <= (a.r * a.r);

	//TODO PenetrationDepth? CollisionNormal?
	return cd;
}

CollisionData kml::iTest(const Ray & a, const Plane & b)
{
	CollisionData cd;
	if (-dot(b.normal, a.direction) > 0)
	{
		cd.isOverlap = 0 <= dot(b.normal, (a.position - b.position)) / -dot(b.normal, a.direction) <= a.length;
	}
	else
	{
		cd.isOverlap = false;
	}

	//TODO PenetrationDepth? CollisionNormal?

	return cd;
}

CollisionData kml::iTest(const ConvexHull & A, const ConvexHull & B)
{
	/*CollisionData cd = { false, INFINITY };
	
	std::vector<vec2> axes;
	
	axes.reserve(A.verts.size());
	for (int i = 0; i < A.verts.size(); ++i)
		axes.push_back(perp(A.verts[i] - A.verts[(i + 1) % A.verts.size()]).normal);


	return cd;*/
	return CollisionData();
}

CollisionData kml::iTest(const ConvexHull & A, const Circle & b)
{
	return CollisionData();
}

CollisionData kml::iTest(const ConvexHull & A, const Ray & r)
{
	//CollisionData cd = { false, INFINITY }; // setup return value

	//std::vector<vec2> axes;

	//axes.reserve(A.verts.size());
	//for (int i = 0; i < A.verts.size(); ++i)
	//	axes.push_back(perp(A.verts[i] - A.verts[(i + 1) % A.verts.size()]).normal);

	//float tmin = 0,  //"Entering" scalar for the ray
	//	tmax = 1;  //"Leaving"  scalar for the ray            

	//vec2 cnormal;
	//float tpmin;

	//for (int i = 0; i < axes.size(); ++i)
	//{
	//	float N = dot(axes[i], r.position - A.verts[i]);
	//	float D = -dot(axes[i], r.direction);

	//	float t = N / D;

	//	if (D < 0 && t > tmin)
	//	{
	//		tmin = fmaxf(tmin, t);
	//		cnormal = axes[i];
	//		cd = { tmin < tmax, (tmax - tmin) * r.length, axes[i], r.position + r.direction * r.length *tmin };
	//	}
	//	else    tmax = fminf(tmax, t);

	//	if (tmin > tmax) return cd;
	//}
	//return cd;
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
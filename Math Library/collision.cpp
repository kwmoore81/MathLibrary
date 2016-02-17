
////#include <cmath>
//#include <list>
//#include <algorithm>
//#include "collision.h"
//
//using namespace kml;
//// untested - algorithm sound but could be typos
//CollisionData sat_hull(const ConvexHull &A, const ConvexHull &B)
//{
//	CollisionData cd = { false, INFINITY }; // setup return value
//
//	std::vector<vec2> axes;
//	axes.reserve(A.verts.size() + B.verts.size());
//
//	for (int i = 0; i < A.verts.size(); ++i) {
//		//kml::vec2 vectorBetween = A.verts[i] - A.verts[(i + 1) % A.verts.size()];
//		//kml::vec2 normal = vectorBetween.normal();
//		//kml::vec2 perpOfNormal = normal.perp();
//		//axes.push_back(perpOfNormal);
//		axes.push_back(perp((A.verts[i] - A.verts[(i + 1) % A.verts.size()]).normal()));
//	}
//
//	for (int i = 0; i < B.verts.size(); ++i)
//	{
//		//kml::vec2 vectorBetween = B.verts[i] - B.verts[(i + 1) % B.verts.size()];
//		//kml::vec2 normal = vectorBetween.normal();
//		//kml::vec2 perpOfNormal = normal.perp();
//		//axes.push_back(perpOfNormal);
//		axes.push_back(perp((B.verts[i] - B.verts[(i + 1) % B.verts.size()]).normal()));
//	}
//		
//
//	for (int j = 0; j < axes.size(); ++j)
//	{
//		float amin = INFINITY, amax = -INFINITY;
//		float bmin = INFINITY, bmax = -INFINITY;
//
//		for (int i = 0; i < A.verts.size(); ++i)
//		{
//			float pp = dot(axes[j], A.verts[i]);
//			amin = fminf(pp, amin);
//			amax = fminf(pp, amax);
//		}
//
//		for (int i = 0; i < B.verts.size(); ++i)
//		{
//			float pp = dot(axes[j], B.verts[i]);
//			amin = fminf(pp, amin);
//			amax = fminf(pp, amax);
//		}
//
//		float pdepth = fminf(amax - bmin, bmax - amin);
//
//		if (pdepth < cd.PenetrationDepth)
//		{
//			cd = { pdepth < 0, pdepth, axes[j] };
//			if (pdepth < 0) return cd;
//		}
//	}
//	return cd;
//}
//
//// untested - algorithm sound but could be typos
//CollisionData sat_hull_ray(const ConvexHull &A, const Ray &r)
//{
//	CollisionData cd = { false, INFINITY }; // setup return value
//
//	std::vector<vec2> axes;
//
//	axes.reserve(A.verts.size());
//	for (int i = 0; i < A.verts.size(); ++i)
//		axes.push_back(perp((A.verts[i] - A.verts[(i + 1) % A.verts.size()]).normal()));
//
//
//	float tmin = 0,  //"Entering" scalar for the ray
//		tmax = 1;  //"Leaving"  scalar for the ray            
//
//	vec2 cnormal;
//	float tpmin;
//
//	for (int i = 0; i < axes.size(); ++i)
//	{
//		float N = dot(axes[i], r.position - A.verts[i]);
//		float D = -dot(axes[i], r.direction);
//
//		float t = N / D;
//
//		if (D < 0 && t > tmin)
//		{
//			tmin = fmaxf(tmin, t);
//			cnormal = axes[i];
//			cd = { tmin < tmax, (tmax - tmin) * r.length, axes[i], r.position + r.direction * r.length *tmin };
//		}
//		else    tmax = fminf(tmax, t);
//
//		if (tmin > tmax) return cd;
//	}
//	return cd;
//}
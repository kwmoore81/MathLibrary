#include "shapes.h"

using namespace kml;

AABB kml::operator*(const mat3 &m, const AABB &a)
{
	vec2 omin = a.min();
	vec2 omax = a.max();
	
	vec2 rmin = m[2].xy;
	vec2 rmax = m[2].xy;

	float p, q;

	for (unsigned j = 0; j < 2; ++j)
		for (unsigned i = 0; i < 2; i++)
		{
			p = omin[i] * m[i][j];
			q = omax[i] * m[i][j];

			if (p < q) std::swap(p, q);
			rmin[j] += p;
			rmax[j] += q;
		}
	return{ (rmin + rmax) / 2, (rmin - rmax) / 2 };
}

Circle kml::operator*(const mat3 &m, const Circle &a)
{
	Circle ret;
	ret.position = (m * vec3(a.position.x, a.position.y, 1)).xy;

	vec3 xrad(a.r, 0, 0);
	vec3 yrad(0, a.r, 0);

	ret.r = fmaxf((m*xrad).magnitude(), (m*yrad).magnitude());

	return ret;
}

Ray kml::operator*(const mat3 &m, const Ray &a)
{
	vec3 dir = vec3(a.direction.x, a.direction.y, 0) * a.length;
	vec3 pos(a.position.x, a.position.y, 1);

	return{ (m * pos).xy, (m * dir).xy.normal(), dir.magnitude() };
}

Plane kml::operator*(const mat3 &m, const Plane &a)
{
	vec3 nor(a.normal.x, a.normal.y, 0);
	vec3 pos(a.position.x, a.position.y, 1);

	return{ (m * pos).xy,(m * nor).xy };
}

ConvexHull kml::operator*(const mat3 &m, const ConvexHull &a)
{
	ConvexHull ret;
	for each(vec2 p in ret.verts)
		ret.verts.push_back((m * vec3(p.x, p.y, 1)).xy);

	return ret;
}
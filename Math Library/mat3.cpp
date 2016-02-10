#include "mat3.h"

using namespace kml;

mat3 kml::operator+(const mat3 & a, const mat3 & b)
{
	return mat3();
}

mat3 kml::operator*(const mat3 &a, const mat3 &b)
{
	mat3 r, A = a.transpose();

	r.c[0] = vec3(dot(A.c[0], b.c[0]), dot(A.c[1], b.c[0]), dot(A.c[2], b.c[0]));
	r.c[1] = vec3(dot(A.c[0], b.c[1]), dot(A.c[1], b.c[1]), dot(A.c[2], b.c[1]));
	r.c[2] = vec3(dot(A.c[0], b.c[2]), dot(A.c[1], b.c[2]), dot(A.c[2], b.c[2]));
	
	return r;
}

vec3 kml::operator*(const mat3 &a, const vec3 &b)
{
	mat3 A = a.transpose();
	vec3 r;

	r.x = dot(A.c[0], b);
	r.y = dot(A.c[1], b);
	r.z = dot(A.c[2], b);

	return r;
}
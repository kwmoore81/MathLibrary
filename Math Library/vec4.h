#pragma once
#include "vec3.h"

/*
Example memory layouts and data structure designs for math types.
They make heavy use of 'untagged' unions and structures to avoid
the potentially nebulous performance costs, implementation details,
and duplicity of operator overloading.
Esmeralda Salamone, esmes@aie.edu.au, 1/25/2016
For instructional use.
*/

namespace kml
{
	__declspec(align(32)) struct vec4
	{
		union
		{
			vec3 xyz;
			vec3 rgb;
			vec3 stp;
			float v[4];
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
			struct { float s, t, p, q; };
		};
	};

	vec4 normal(const vec4 &a);

	float magnitude(const vec4 &a);
	float dot(const vec4 &a, const vec4 &b);
	float distance(const vec4 &a, const vec4 &b);

	vec4 min(const vec4 &a, const vec4 &b);
	vec4 max(const vec4 &a, const vec4 &b);
	vec4 clamp(const vec4 &a, const vec4 &min, const vec4 &max);

	float angleBetween(const vec4 &a, const vec4 &b);

	vec4 mix(const vec4 &start, const vec4 &end, float t);
	vec4 lerp(const vec4 &start, const vec4 &end, float t);

	vec4 reflect(const vec4 &incident, const vec4 &normal);
	vec4 project(const vec4 &a, const vec4 &b);

	vec4 operator-(const vec4 &a);

	vec4 operator+(const vec4 &a, const vec4 &b);
	vec4 operator-(const vec4 &a, const vec4 &b);
	vec4 operator/(const vec4 &a, float b);
	vec4 operator*(const vec4 &a, float b);

	vec4 &operator+=(vec4 &a, const vec4 &b);
	vec4 &operator-=(vec4 &a, const vec4 &b);
	vec4 &operator/=(vec4 &a, float b);
	vec4 &operator*=(vec4 &a, float b);


	bool operator> (const vec4 &a, const vec4 &b);
	bool operator>=(const vec4 &a, const vec4 &b);
	bool operator< (const vec4 &a, const vec4 &b);
	bool operator<=(const vec4 &a, const vec4 &b);

	bool operator==(const vec4 &a, const vec4 &b);
	bool operator!=(const vec4 &a, const vec4 &b);
}

#pragma once
#pragma once
#include <cfloat>
#include <cmath>
#include <cassert>
//#include "vec2.h"
//FLT_EPSILON for comparison operators
//float a, b;
//a == b;
// (a - FLT_EPSILON) < b && b < (a + FLT_EPSILON)
//fabs(a-b) < FLT_EPSILON

#define PI 3.14159265359

namespace kml
{
	struct vec3
	{
		float x, y, z;
		
		vec3() {}
		vec3(float a_x, float a_y, float a_z)
			: x(a_x), y(a_y), z(a_z) {}

		float magnitude() const { return sqrt(x*x + y*y + z*z); }
		/*union
		{
			vec2 xy;
			vec2 st;
			struct { float x, y, z; };
			struct { float r, g, b; };
			struct { float s, t, p; };
			float v[3];
		};*/
		
		//unary oerations
		//float magnitude() const; //pythagorean theorm
		vec3 normal() const; //divide by magnitude
		vec3 perp() const; //<-y,x>
		void normalize();
		vec3 operator-() const; //<-x,-y>

	};
	//binary operators
	float dot(const vec3 &lhs, const vec3 &rhs);
	vec3 operator+(const vec3 &lhs, const vec3 &rhs);
	vec3 operator+=(const vec3 &lhs, const vec3 &rhs);
	vec3 operator-(const vec3 &lhs, const vec3 &rhs);
	vec3 operator-=(const vec3 &lhs, const vec3 &rhs);

	vec3 operator*(const vec3 &lhs, float rhs);
	vec3 operator*=(const vec3 &lhs, float rhs);
	vec3 operator/(const vec3 &lhs, float rhs);
	vec3 operator/=(const vec3 &lhs, float rhs);

	bool operator==(const vec3 &lhs, const vec3 &rhs);
	bool operator!=(const vec3 &lhs, const vec3 &rhs);
	bool operator<(const vec3 &lhs, const vec3 &rhs);
	bool operator<=(const vec3 &lhs, const vec3 &rhs);
	bool operator>(const vec3 &lhs, const vec3 &rhs);
	bool operator>=(const vec3 &lhs, const vec3 &rhs);

	vec3 reflect(const vec3 &incident, const vec3 &normal);
	vec3 CrossProduct(float *a, float *b);
	
}


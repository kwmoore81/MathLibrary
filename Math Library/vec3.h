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

using namespace kml;

vec3 kml::reflect(const vec3 & incident, const vec3 & normal)
{
	vec3 reflection;

	reflection.x = incident.x - 2 * (incident.x * normal.x) * normal.x;
	reflection.y = incident.y - 2 * (incident.y * normal.y) * normal.y;
	reflection.z = incident.z - 2 * (incident.z * normal.z) * normal.z;

	return reflection;
}

vec3 vec3::normal() const
{
	return *this / magnitude();
}

vec3 kml::CrossProduct(float *a, float *b)
{
	vec3 product;

	product.x = (a[1] * b[2]) - (a[2] * b[1]);
	product.y = (a[2] * b[0]) - (a[0] * b[2]);
	product.z = (a[0] * b[1]) - (a[1] * b[0]);

	product.normalize();

	return product;
}

inline vec3 vec3::perp() const
{
	vec3 perpVec3;
	//check on this
	perpVec3.x = -y;
	perpVec3.y = x;

	return perpVec3;
}

inline void vec3::normalize()
{
	x = x / magnitude();
	y = y / magnitude();
	z = z / magnitude();
}

inline vec3 vec3::operator-() const
{
	vec3 negVec3;

	negVec3.x = -x;
	negVec3.y = -y;
	negVec3.z = -z;

	return negVec3;
}

float kml::dot(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

vec3 kml::operator+(const vec3 & lhs, const vec3 & rhs)
{
	vec3 plusVec3;

	plusVec3.x = lhs.x + rhs.x;
	plusVec3.y = lhs.y + rhs.y;
	plusVec3.z = lhs.z + rhs.z;

	return plusVec3;
}

vec3 kml::operator+=(const vec3 & lhs, const vec3 & rhs)
{
	vec3 plEqVec3;

	plEqVec3.x = lhs.x + rhs.x;
	plEqVec3.y = lhs.y + rhs.y;
	plEqVec3.z = lhs.z + rhs.z;

	return plEqVec3;
}

vec3 kml::operator-(const vec3 & lhs, const vec3 & rhs)
{
	vec3 minusVec3;

	minusVec3.x = lhs.x - rhs.x;
	minusVec3.y = lhs.y - rhs.y;
	minusVec3.z = lhs.z - rhs.z;

	return minusVec3;
}

vec3 kml::operator-=(const vec3 & lhs, const vec3 & rhs)
{
	vec3 minusVec3;

	minusVec3.x = lhs.x - rhs.x;
	minusVec3.y = lhs.y - rhs.y;
	minusVec3.z = lhs.z - rhs.z;

	return minusVec3;
}

vec3 kml::operator*(const vec3 & lhs, float rhs)
{
	vec3 multVec3;

	multVec3.x = lhs.x * rhs;
	multVec3.y = lhs.y * rhs;
	multVec3.z = lhs.z * rhs;

	return multVec3;
}

vec3 kml::operator*=(const vec3 & lhs, float rhs)
{
	vec3 multVec3;

	multVec3.x = lhs.x * rhs;
	multVec3.y = lhs.y * rhs;
	multVec3.z = lhs.z * rhs;

	return multVec3;
}

vec3 kml::operator/(const vec3 & lhs, float rhs)
{
	vec3 divVec3;

	divVec3.x = lhs.x / rhs;
	divVec3.y = lhs.y / rhs;
	divVec3.z = lhs.z / rhs;

	return divVec3;
}

vec3 kml::operator/=(const vec3 & lhs, float rhs)
{
	vec3 divVec3;

	divVec3.x = lhs.x / rhs;
	divVec3.y = lhs.y / rhs;
	divVec3.z = lhs.z / rhs;

	return divVec3;
}

bool kml::operator==(const vec3 & lhs, const vec3 & rhs)
{
	if (fabs(lhs.x - rhs.x < FLT_EPSILON) && fabs(lhs.y - rhs.y < FLT_EPSILON) && fabs(lhs.z - rhs.z < FLT_EPSILON)) { return true; }

	else { return false; }
}

bool kml::operator!=(const vec3 & lhs, const vec3 & rhs)
{
	if (fabs(lhs.x - rhs.x < FLT_EPSILON) && fabs(lhs.y - rhs.y < FLT_EPSILON) && fabs(lhs.z - rhs.z < FLT_EPSILON)) { return false; }

	else { return true; }
}

bool kml::operator<(const vec3 & lhs, const vec3 & rhs)
{
	if (fabs(lhs.x < (rhs.x - FLT_EPSILON)) && fabs(lhs.y < (rhs.y - FLT_EPSILON)) && fabs(lhs.z < (rhs.z - FLT_EPSILON))) { return true; }

	else { return false; }
}

bool kml::operator<=(const vec3 & lhs, const vec3 & rhs)
{
	if (fabs(lhs.x <= (rhs.x - FLT_EPSILON)) && fabs(lhs.y <= (rhs.y - FLT_EPSILON)) && fabs(lhs.z <= (rhs.z - FLT_EPSILON))) { return true; }

	else { return false; }
}

bool kml::operator>(const vec3 & lhs, const vec3 & rhs)
{
	if (fabs(lhs.x > (rhs.x + FLT_EPSILON)) && fabs(lhs.y > (rhs.y + FLT_EPSILON)) && fabs(lhs.z > (rhs.z + FLT_EPSILON))) { return true; }

	else { return false; }
}

bool kml::operator>=(const vec3 & lhs, const vec3 & rhs)
{
	if (fabs(lhs.x >= (rhs.x + FLT_EPSILON)) && fabs(lhs.y >= (rhs.y + FLT_EPSILON)) && fabs(lhs.z >= (rhs.z + FLT_EPSILON))) { return true; }

	else { return false; }
}
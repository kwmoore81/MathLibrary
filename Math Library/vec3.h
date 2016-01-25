#pragma once
#pragma once
#include <cfloat>
#include <cmath>
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
		union
		{
			struct { float x, y, z; };
			float v[3];
		};
		//static construction functions
		static vec3 fromAngle(float angle);
		//unary oerations
		float magnitude() const; //pythagorean theorm
		//float angle() const; //atan2f
		vec3 normal() const; //divide by magnitude
		vec3 perp() const; //<-y,x>
		void normalize();
		vec3 operator-() const; //<-x,-y>
		vec3 Reflection() const;

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

	vec3 CrossProduct(float *a, float *b);
}

using namespace kml;

//vec3 vec3::fromAngle(float angle)
//{
//	vec3 angVec2;
//	angle = angle * PI / 180;
//
//	angVec2.x = cos(angle);
//	angVec2.y = sin(angle);
//
//	return angVec2;
//}

float vec3::magnitude() const
{
	return sqrt(x*x + y*y + z*z);
}

inline vec3 kml::vec3::Reflection() const
{
	//check on this
	-vec3::magnitude();
	//-vec3::angle();
	return vec3();
}

vec3 vec3::normal() const
{
	vec3 normVec3;
	normVec3.x = x / vec3::magnitude();
	normVec3.y = y / vec3::magnitude();
	normVec3.z = z / vec3::magnitude();

	return normVec3;
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
	x = x / vec3::magnitude();
	y = y / vec3::magnitude();
	z = z / vec3::magnitude();
}

vec3 CrossProduct(float *a, float *b)
{
	vec3 product;
 
	product.x = (a[1] * b[2]) - (a[2] * b[1]);
	product.y = (a[2] * b[0]) - (a[0] * b[2]);
	product.z = (a[0] * b[1]) - (a[1] * b[0]);
	
	vec3::normalize;

	return product;
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
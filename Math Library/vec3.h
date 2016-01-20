#pragma once
#pragma once
#include <cfloat>
#include <cmath>
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
		float angle() const; //atan2f
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

float vec3::angle() const
{
	return atan2f(y, x, z) * 180 / PI;
}

inline vec3 kml::vec3::Reflection() const
{
	//check on this
	-vec3::magnitude();
	-vec3::angle();
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

inline vec2 vec2::operator-() const
{
	vec2 negVec2;

	negVec2.x = -x;
	negVec2.y = -y;

	return negVec2;
}

float kml::dot(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

vec2 kml::operator+(const vec2 & lhs, const vec2 & rhs)
{
	vec2 plusVec2;

	plusVec2.x = lhs.x + rhs.x;
	plusVec2.y = lhs.y + rhs.y;

	return plusVec2;
}

vec2 kml::operator+=(const vec2 & lhs, const vec2 & rhs)
{
	vec2 plEqVec2;

	plEqVec2.x = lhs.x + rhs.x;
	plEqVec2.y = lhs.y + rhs.y;

	return plEqVec2;
}

vec2 kml::operator-(const vec2 & lhs, const vec2 & rhs)
{
	vec2 minusVec2;

	minusVec2.x = lhs.x - rhs.x;
	minusVec2.y = lhs.y - rhs.y;

	return minusVec2;
}

vec2 kml::operator-=(const vec2 & lhs, const vec2 & rhs)
{
	vec2 minusVec2;

	minusVec2.x = lhs.x - rhs.x;
	minusVec2.y = lhs.y - rhs.y;

	return minusVec2;
}

vec2 kml::operator*(const vec2 & lhs, float rhs)
{
	vec2 multVec2;

	multVec2.x = lhs.x * rhs;
	multVec2.y = lhs.y * rhs;

	return multVec2;
}

vec2 kml::operator*=(const vec2 & lhs, float rhs)
{
	vec2 multVec2;

	multVec2.x = lhs.x * rhs;
	multVec2.y = lhs.y * rhs;

	return multVec2;
}

vec2 kml::operator/(const vec2 & lhs, float rhs)
{
	vec2 divVec2;

	divVec2.x = lhs.x / rhs;
	divVec2.y = lhs.y / rhs;

	return divVec2;
}

vec2 kml::operator/=(const vec2 & lhs, float rhs)
{
	vec2 divVec2;

	divVec2.x = lhs.x / rhs;
	divVec2.y = lhs.y / rhs;

	return divVec2;
}

bool kml::operator==(const vec2 & lhs, const vec2 & rhs)
{
	if (fabs(lhs.x - rhs.x < FLT_EPSILON) && fabs(lhs.y - rhs.y < FLT_EPSILON)) { return true; }

	else { return false; }
}

bool kml::operator!=(const vec2 & lhs, const vec2 & rhs)
{
	if (fabs(lhs.x - rhs.x < FLT_EPSILON) && fabs(lhs.y - rhs.y < FLT_EPSILON)) { return false; }

	else { return true; }
}

bool kml::operator<(const vec2 & lhs, const vec2 & rhs)
{
	if (fabs(lhs.x < (rhs.x - FLT_EPSILON)) && fabs(lhs.y < (rhs.y - FLT_EPSILON))) { return true; }

	else { return false; }
}

bool kml::operator<=(const vec2 & lhs, const vec2 & rhs)
{
	if (fabs(lhs.x <= (rhs.x - FLT_EPSILON)) && fabs(lhs.y <= (rhs.y - FLT_EPSILON))) { return true; }

	else { return false; }
}

bool kml::operator>(const vec2 & lhs, const vec2 & rhs)
{
	if (fabs(lhs.x > (rhs.x + FLT_EPSILON)) && fabs(lhs.y > (rhs.y + FLT_EPSILON))) { return true; }

	else { return false; }
}

bool kml::operator>=(const vec2 & lhs, const vec2 & rhs)
{
	if (fabs(lhs.x >= (rhs.x + FLT_EPSILON)) && fabs(lhs.y >= (rhs.y + FLT_EPSILON))) { return true; }

	else { return false; }
}
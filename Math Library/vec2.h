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
	struct vec2
	{
		union
		{
			struct { float x, y; };
			float v[2];
		};
		//static construction functions
		static vec2 fromAngle(float angle);
		//unary oerations
		float magnitude() const; //pythagorean theorm
		float angle() const; //atan2f
		vec2 normal() const; //divide by magnitude
		vec2 perp() const; //<-y,x>
		void normalize();
		vec2 operator-() const; //<-x,-y>
		
	};
	//binary operators
	float dot(const vec2 &lhs, const vec2 &rhs);
	vec2 operator+(const vec2 &lhs, const vec2 &rhs);
	vec2 operator+=(const vec2 &lhs, const vec2 &rhs);
	vec2 operator-(const vec2 &lhs, const vec2 &rhs);
	vec2 operator-=(const vec2 &lhs, const vec2 &rhs);

	vec2 operator*(const vec2 &lhs, float rhs);
	vec2 operator*=(const vec2 &lhs, float rhs);
	vec2 operator/(const vec2 &lhs, float rhs);
	vec2 operator/=(const vec2 &lhs, float rhs);

	bool operator==(const vec2 &lhs, const vec2 &rhs);
	bool operator!=(const vec2 &lhs, const vec2 &rhs);
	bool operator<(const vec2 &lhs, const vec2 &rhs);
	bool operator<=(const vec2 &lhs, const vec2 &rhs);
	bool operator>(const vec2 &lhs, const vec2 &rhs);
	bool operator>=(const vec2 &lhs, const vec2 &rhs);
	
}

using namespace kml;

vec2 vec2::fromAngle(float angle)
{
	vec2 angVec2;
	angle = angle * PI / 180;

	angVec2.x = cos(angle);
	angVec2.y = sin(angle);
	
	return angVec2;
}

float vec2::magnitude() const
{
	return sqrt(x*x + y*y);
}

float vec2::angle() const
{
	return atan2f(y, x) * 180 / PI;
}

vec2 vec2::normal() const
{
	vec2 normVec2;
	  normVec2.x = x / vec2::magnitude();
	  normVec2.y = y / vec2::magnitude();

	return normVec2;
}

inline vec2 vec2::perp() const
{
	vec2 perpVec2;

	perpVec2.x = -y;
	perpVec2.y = x;
	
	return perpVec2;
}

inline void vec2::normalize()
{
	x = x / vec2::magnitude();
	y = y / vec2::magnitude();

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

vec2 kml::operator*(const vec2 & lhs, float rhs)
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

bool kml::operator==(const vec2 & lhs, const vec2 & rhs)
{
	if (fabs(lhs.x - rhs.x < FLT_EPSILON) && fabs(lhs.y - rhs.y < FLT_EPSILON)) { return true; }
	
	else { return false; }
}

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
	vec2 operator*(float lhs, const vec2 & rhs);
	vec2 operator*=(const vec2 &lhs, float rhs);
	vec2 operator/(const vec2 &lhs, float rhs);
	vec2 operator/=(const vec2 &lhs, float rhs);

	bool operator==(const vec2 &lhs, const vec2 &rhs);
	bool operator!=(const vec2 &lhs, const vec2 &rhs);
	bool operator<(const vec2 &lhs, const vec2 &rhs);
	bool operator<=(const vec2 &lhs, const vec2 &rhs);
	bool operator>(const vec2 &lhs, const vec2 &rhs);
	bool operator>=(const vec2 &lhs, const vec2 &rhs);
	
	vec2 min(const vec2 &a, const vec2 &b);
	vec2 max(const vec2 &a, const vec2 &b);
	vec2 clamp(const vec2 &a, const vec2 &min, const vec2 &max);
	vec2 mix(const vec2 &start, const vec2 &end, float t);
	vec2 lerp(const vec2 &start, const vec2 &end, float t);

	vec2 reflect(const vec2 &incident, const vec2 &normal);
	vec2 project(const vec2 &a, const vec2 &b);

	//Intersections
	
	float Circle(float x1, float y1, float r1, float x2, float y2, float r2);
	float AABB(float x1, float y1, float hw1, float hh1, float x2, float y2, float hw2, float hh2);
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
	return *this / magnitude();
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

vec2 kml::min(const vec2 & a, const vec2 & b)
{
	if (a < b)
		return a;

	else
		return b;
}

vec2 kml::max(const vec2 & a, const vec2 & b)
{
	if (a > b)
		return a;

	else
		return b;
}

vec2 kml::mix(const vec2 & start, const vec2 & end, float t)
{
	vec2 mixed;

	mixed.x = start.x * (1 - t) + end.x * t;
	mixed.y = start.x * (1 - t) + end.x * t;

	return mixed;
}

vec2 kml::lerp(const vec2 & start, const vec2 & end, float t)
{
	vec2 lerped;

	lerped.x = (1 - t) * start.x + t * end.x;
	lerped.y = (1 - t) * start.y + t * end.y;
	
	return lerped;
}

vec2 kml::clamp(const vec2 &a, const vec2 &min, const vec2 &max)
{
	vec2 clamped;

	clamped.x = fmax(fmin(min.x, a.x), min.x);
	clamped.y = fmax(fmin(min.y, a.y), min.x);

	return clamped;
}

float kml::dot(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

vec2 kml::reflect(const vec2 & incident, const vec2 & normal)
{
	vec2 reflection;

		reflection.x = incident.x - 2 * (incident.x * normal.x) * normal.x;
		reflection.y = incident.y - 2 * (incident.y * normal.y) * normal.y;
	
		return reflection;
}

vec2 kml::project(const vec2 & a, const vec2 & b)
{
	
	return kml::dot(a, b) * b.normal();
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

vec2 kml::operator*(float lhs, const vec2 & rhs) 
{
	return rhs * lhs;
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

float kml::Circle(float x1, float y1, float r1, float x2, float y2, float r2)
{
	return (r1 + r2) - sqrtf((x1 - x2) * (x1-x2) + (y1 - y2) * (y1 - y2));
}

float kml::AABB(float x1, float y1, float hw1, float hh1, float x2, float y2, float hw2, float hh2)
{
	float b1 = y1 - hh1;
	float t1 = y1 + hh1;
	float l1 = x1 - hw1;
	float r1 = x1 + hw1;

	float b2 = y2 - hh2;
	float t2 = y2 + hh2;
	float l2 = x2 - hw2;
	float r2 = x2 + hw2;

	float xt = fmin(r1 - l2, r2 - l1);
	float yt = fmin(t1 - b2, t2 - b1);

	return fmin(xt, yt);
}
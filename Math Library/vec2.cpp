#include "vec2.h"

using namespace kml;

kml::vec2 kml::vec2::fromAngle(float angle)
{
	return{ cosf(angle), sinf(angle) };
}

float kml::vec2::magnitude() const
{
	return sqrt(x*x + y*y);
}

float kml::vec2::angle() const
{
	return atan2f(y, x);
}

kml::vec2 kml::vec2::normal() const
{
	return *this / magnitude();
}

//kml::vec2 kml::vec2::perp() const
//{
//	vec2 _perp;
//	_perp.y = -y;
//	_perp.x = x;
//	return _perp;
//}

vec2 kml::perp(vec2 &a)
{
	return vec2({ -a.y, a.x });
}

vec2 kml::vec2::normalize()
{
	vec2 norm;

	norm.x = x / magnitude();
	norm.y = y / magnitude();

	return norm;
}

kml::vec2 kml::min(const vec2 & a, const vec2 & b)
{
	if (a < b)
		return a;

	else
		return b;
}

kml::vec2 kml::max(const vec2 & a, const vec2 & b)
{
	if (a > b)
		return a;

	else
		return b;
}

kml::vec2 kml::mix(const vec2 & start, const vec2 & end, float t)
{
	vec2 mixed;

	mixed.x = start.x * (1 - t) + end.x * t;
	mixed.y = start.x * (1 - t) + end.x * t;

	return mixed;
}

kml::vec2 kml::lerp(const vec2 & start, const vec2 & end, float t)
{
	vec2 lerped;

	lerped.x = (1 - t) * start.x + t * end.x;
	lerped.y = (1 - t) * start.y + t * end.y;

	return lerped;
}

kml::vec2 kml::clamp(const vec2 &a, const vec2 &min, const vec2 &max)
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

kml::vec2 kml::reflect(const vec2 & incident, const vec2 & normal)
{
	vec2 reflection;

	reflection.x = incident.x - 2 * (incident.x * normal.x) * normal.x;
	reflection.y = incident.y - 2 * (incident.y * normal.y) * normal.y;

	return reflection;
}

kml::vec2 kml::project(const vec2 & a, const vec2 & b)
{
	return kml::dot(a, b) * b.normal();
}

vec2 kml::snap(const vec2 & val, const vec2 & lower, const vec2 & upper)
{
	return{ val.x - lower.x < upper.x - val.x ? lower.x : upper.x,
		val.y - lower.y < upper.y - val.y ? lower.y : upper.y };
}

kml::vec2 kml::operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2(lhs.x + rhs.x, lhs.y + rhs.y);
}

kml::vec2 kml::operator+=(const vec2 & lhs, const vec2 & rhs)
{
	vec2 plEqVec2;

	plEqVec2.x = lhs.x + rhs.x;
	plEqVec2.y = lhs.y + rhs.y;

	return plEqVec2;
}

kml::vec2 kml::operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2(lhs.x - rhs.x, lhs.y - rhs.y);
}

kml::vec2 kml::operator-=(const vec2 & lhs, const vec2 & rhs)
{
	vec2 minusVec2;

	minusVec2.x = lhs.x - rhs.x;
	minusVec2.y = lhs.y - rhs.y;

	return minusVec2;
}

kml::vec2 kml::operator*(float lhs, const vec2 & rhs)
{
	return rhs * lhs;
}

kml::vec2 kml::operator*(const vec2 & lhs, float rhs)
{
	return vec2(lhs.x * rhs, lhs.y * rhs);
}


kml::vec2 kml::operator*=(const vec2 & lhs, float rhs)
{
	vec2 multVec2;

	multVec2.x = lhs.x * rhs;
	multVec2.y = lhs.y * rhs;

	return multVec2;
}

kml::vec2 kml::operator/(const vec2 & lhs, float rhs)
{
	return vec2(lhs.x / rhs, lhs.y / rhs);
}

kml::vec2 kml::operator/=(const vec2 & lhs, float rhs)
{
	vec2 divVec2;

	divVec2.x = lhs.x / rhs;
	divVec2.y = lhs.y / rhs;

	return divVec2;
}

inline bool kml::operator==(const vec2 & lhs, const vec2 & rhs)
{
	/*if (fabs(lhs.x - rhs.x < FLT_EPSILON) && fabs(lhs.y - rhs.y < FLT_EPSILON)) { return true; }

	else { return false; }*/

	return rhs.x - FLT_EPSILON < lhs.x && lhs.x < rhs.x + FLT_EPSILON &&
		   rhs.y - FLT_EPSILON < lhs.y && lhs.y < rhs.y + FLT_EPSILON;
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
	if (fabs(lhs.x - rhs.x <= FLT_EPSILON) && fabs(lhs.y - rhs.y <= FLT_EPSILON)) { return true; }

	else { return false; }
}

bool kml::operator>(const vec2 & lhs, const vec2 & rhs)
{
	if (fabs(lhs.x > (rhs.x + FLT_EPSILON)) && fabs(lhs.y > (rhs.y + FLT_EPSILON))) { return true; }

	else { return false; }
}

bool kml::operator>=(const vec2 & lhs, const vec2 & rhs)
{
	if (fabs(lhs.x - rhs.x >= -FLT_EPSILON) && fabs(lhs.y - rhs.y >= -FLT_EPSILON)) { return true; }

	else { return false; }
}

//float Circle(float x1, float y1, float r1, float x2, float y2, float r2)
//{
//	return (r1 + r2) - sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
//}
//
//float AABB(float x1, float y1, float hw1, float hh1, float x2, float y2, float hw2, float hh2)
//{
//	float b1 = y1 - hh1;
//	float t1 = y1 + hh1;
//	float l1 = x1 - hw1;
//	float r1 = x1 + hw1;
//
//	float b2 = y2 - hh2;
//	float t2 = y2 + hh2;
//	float l2 = x2 - hw2;
//	float r2 = x2 + hw2;
//
//	float xt = fmin(r1 - l2, r2 - l1);
//	float yt = fmin(t1 - b2, t2 - b1);
//
//	return fmin(xt, yt);
//}
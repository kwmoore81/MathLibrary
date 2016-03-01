#include "vec3.h"

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

//vec3 kml::perp(vec3 & a)
//{
//	return vec3({ -a.y, a.x, a.z});
//}

inline void vec3::normalize()
{
	x = x / magnitude();
	y = y / magnitude();
	z = z / magnitude();
}

//inline vec3 vec3::operator-() const
//{
//	vec3 negVec3;
//
//	negVec3.x = -x;
//	negVec3.y = -y;
//	negVec3.z = -z;
//
//	return negVec3;
//}

float kml::dot(const vec3 & lhs, const vec3 & rhs)
{
	//return lhs.x * rhs.x + rhs.y * lhs.y + rhs.z * lhs.z;
	float xval = lhs.x * rhs.x;
	float yval = lhs.y * rhs.y;
	float zval = lhs.z * rhs.z;

	return xval + yval + zval;
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
	/*vec3 minusVec3;

	minusVec3.x = lhs.x - rhs.x;
	minusVec3.y = lhs.y - rhs.y;
	minusVec3.z = lhs.z - rhs.z;*/

	return vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
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

	return{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 kml::operator*=(const vec3 & lhs, float rhs)
{
	/*vec3 multVec3;

	multVec3.x = lhs.x * rhs;
	multVec3.y = lhs.y * rhs;
	multVec3.z = lhs.z * rhs;

	return multVec3;*/

	return{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 kml::operator/(const vec3 & lhs, float rhs)
{

	return vec3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

vec3 kml::operator/=(const vec3 & lhs, float rhs)
{
	/*vec3 divVec3;

	divVec3.x = lhs.x / rhs;
	divVec3.y = lhs.y / rhs;
	divVec3.z = lhs.z / rhs;

	return divVec3;*/

	return vec3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

inline bool kml::operator==(const vec3 & lhs, const vec3 & rhs)
{
	/*if (fabs(lhs.x - rhs.x < FLT_EPSILON) && fabs(lhs.y - rhs.y < FLT_EPSILON) && fabs(lhs.z - rhs.z < FLT_EPSILON)) { return true; }

	else { return false; }*/

	return rhs.x - FLT_EPSILON < lhs.x && lhs.x < rhs.x + FLT_EPSILON &&
		   rhs.y - FLT_EPSILON < lhs.y && lhs.y < rhs.y + FLT_EPSILON &&
		   rhs.z - FLT_EPSILON < lhs.z && lhs.z < rhs.z + FLT_EPSILON;
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


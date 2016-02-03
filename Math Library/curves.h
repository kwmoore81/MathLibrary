#pragma once
#include"vec2.h"
#include"vec3.h"
/*
Could make an object to represent a chain of curves.
*/
namespace kml
{
	vec2 bezierQuad(const vec2 &start, const vec2 &cp1, const vec2 &end, float t);
	vec2 bezierCubic(const vec2 &start, const vec2 &cp1, const vec2 &cp2, const vec2 &end, float t);
	vec2 hermiteSpline(const vec2 &start, const vec2 &end, const vec2 &stan, const vec2 &tend, float t);
	vec2 cardinalSpline(const vec2 &start, const vec2 &cp1, const vec2 &end, float a, float t);

	vec3 bezierQuad(const vec3 &start, const vec3 &cp1, const vec3 &end, float t);
	vec3 bezierCubic(const vec3 &start, const vec3 &cp1, const vec3 &cp2, const vec3 &end, float t);
	vec3 hermiteSpline(const vec3 &start, const vec3 &end, const vec3 &stan, const vec3 &tend, float t);
	vec3 cardinalSpline(const vec3 &start, const vec3 &cp1, const vec3 &end, float a, float t);
}
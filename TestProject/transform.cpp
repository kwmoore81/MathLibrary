#include "transform.h"

using namespace kml;

kml::Transform::Transform() : e_parent(nullptr), pos({ 0, 0 }), scale({ 1, 1 }), angle(0) {}

kml::Transform::~Transform()
{
	auto t = e_children;
	for each(Transform *child in t)
		child->setParent(e_parent);

	setParent(nullptr);
}

void kml::Transform::setParent(Transform * p)
{
	if (e_parent)
		e_parent->e_children.remove(this);

	if (p)
		p->e_children.push_front(this);

	e_parent = p;

}

mat3 kml::Transform::getGlobalTransform() const
{
	return (e_parent ? e_parent->getGlobalTransform() : mat3::identity())
		* mat3::translate(pos)
		* mat3::scale(scale)
		* mat3::rotate(angle);
}

void kml::Transform::setPos(const vec2 & a_position)
{
	pos = a_position;
}

void kml::Transform::setScale(const vec2 & a_scale)
{
	scale = a_scale;
}

void kml::Transform::setAngle(float deg)
{
	angle = deg;
}

vec2 kml::Transform::getpos() const
{
	return pos;
}

vec2 kml::Transform::getscale() const
{
	return scale;
}

float kml::Transform::getAngle() const
{
	return angle;
}

vec2 kml::Transform::getRight() const
{
	return vec2::fromAngle(angle);
}

vec2 kml::Transform::getUp() const
{
	return perp(vec2::fromAngle(angle));
}


#pragma once
#include "Math.h"
#include <list>

namespace kml
{
	class Transform
	{
		
		Transform *e_parent;
		vec2 pos, scale;
		float angle;
		std::list<Transform *> e_children;
	public:
		Transform();
		~Transform();

		mat3 getGlobalTransform() const;
		//mat4 getGlobalTransform() const;

		void setParent(Transform *p);
		void setPos(const vec2 &pos);
		void setScale(const vec2 &scale);
		void setAngle(float deg);

		vec2 getpos() const;
		vec2 getscale() const;
		float getAngle() const;
		

	};
}
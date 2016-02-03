#pragma once
#include "kmath.h"
//#include "mat3.h"
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

		mat3 getGlobalTransform();
		

		void setParent(Transform *p);
		void setPos(const vec2 &pos);
		void setScale(const vec2 &scale);
		void setAngle(float deg);

		vec2 getpos() const;
		vec2 getscale() const;
		float getAngle() const;
		
		vec2 getRight() const;
		vec2 getUp() const;
	};
}
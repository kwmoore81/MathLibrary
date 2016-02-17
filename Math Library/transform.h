#pragma once
#include "kmath.h"
//#include "mat3.h"
#include <list>



namespace kml
{
	class Transform
	{
		
		Transform *e_parent;
		std::list<Transform *> e_children;
		vec2 pos, scale;
		float angle;
		
	public:
		Transform();
		~Transform();

		mat3 getGlobalTransform() const;
		

		void setParent (Transform *);
		void setPos (const vec2 &);
		void setScale (const vec2 &);
		void setAngle (float);

		vec2 getpos() const;
		vec2 getscale() const;
		float getAngle() const;
		
		vec2 getRight() const;
		vec2 getUp() const;
	};
}
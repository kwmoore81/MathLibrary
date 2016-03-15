#pragma once
#include "GCData.h"
#include "shapes.h"
#include "kmath.h"
#include "transform.h"
#include "collision.h"

namespace kml
{
	class Collider : public GCData<Collider>
	{
	public:
		enum SHAPE { e_CIRCLE = 1, e_AABB = 2, e_RAY = 4, e_PLANE = 8 }shape;
		Collider() : shape(e_CIRCLE), circle{ {0 , 0}, 1 } {}
		union
		{
			Circle circle;
			AABB aabb;
			Ray ray;
			Plane plane;
		};

		
		ConvexHull chull;
	};

	CollisionData EvaluateCollision(const Transform &at, const Collider &ac, const Transform &bt, const Collider &bc);

}
/*
template<typename T>
class ColliderT
{
public:
T shape;
ConvexHull chull;
operator const T&() const { return shape; }
};

template<typename T, typename R>
inline CollisionData EvaluateCollisionT(const Transform &at, const ColliderT<T> &ac,
const Transform &bt, const ColliderT<R> &bc)
{
return itest(at.getGlobalTransform() * ac, bt.getGlobalTransform() * bt);
}
*/
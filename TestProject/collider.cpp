
#include "collider.h"
#include "transform.h"
#include "collision.h"

using namespace kml;


CollisionData EvaluateCollision(const Transform &at, const Collider &ac,
	const Transform &bt, const Collider &bc)
{
	Transform t_lhs = at;
	Transform t_rhs = bt;
	Collider lhs = ac;
	Collider rhs = bc;
	if (lhs.shape > rhs.shape)
	{
		std::swap(lhs, rhs);
		std::swap(t_lhs, t_rhs);
	}

	CollisionData cd;

	/*switch (lhs.shape | rhs.shape)
	{
	case Collider::e_CIRCLE:
		return iTest(t_lhs.getGlobalTransform() * lhs.circle,
			t_rhs.getGlobalTransform() * rhs.circle);

	case Collider::e_CIRCLE | Collider::e_AABB:
		return iTest(t_lhs.getGlobalTransform() * lhs.circle,
			t_rhs.getGlobalTransform() * rhs.aabb);

	case Collider::e_CIRCLE | Collider::e_RAY:
		return iTest(t_lhs.getGlobalTransform() * lhs.circle,
			t_rhs.getGlobalTransform() * rhs.ray);

	case Collider::e_CIRCLE | Collider::e_PLANE:
		return iTest(t_lhs.getGlobalTransform() * lhs.circle,
			t_rhs.getGlobalTransform() * rhs.plane);

	case Collider::e_AABB:
		return iTest(t_lhs.getGlobalTransform() * lhs.aabb,
			t_rhs.getGlobalTransform() * rhs.aabb);

	case Collider::e_AABB | Collider::e_RAY:
		return iTest(t_lhs.getGlobalTransform() * lhs.aabb,
			t_rhs.getGlobalTransform() * rhs.ray);

	case Collider::e_AABB | Collider::e_PLANE:
		return iTest(t_lhs.getGlobalTransform() * lhs.aabb,
			t_rhs.getGlobalTransform() * rhs.plane);

	case Collider::e_RAY | Collider::e_PLANE:
		return iTest(t_lhs.getGlobalTransform() * lhs.ray,
			t_rhs.getGlobalTransform() * rhs.plane);
	}*/

	return cd;
}

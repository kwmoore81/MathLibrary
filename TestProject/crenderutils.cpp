#include "sfwdraw.h"
#include "crenderutils.h"

void drawMatrix(const Matrix3 &a)
{
	Vector2 &pos = a[2].xy;
	Vector2 up = pos + a[1].xy;
	Vector2 right = pos + a[0].xy;

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);
}

void drawTransform(const Transform &t) { drawMatrix(t.getGlobalTransform() * Matrix3::scale({ 30,30 })); }

void drawRigidbody(const Transform &t, const Rigidbody &rb)
{
	Vector2 pos = t.getPosition();
	Vector2 acc = pos + rb.acceleration;
	Vector2 vel = pos + rb.velocity;

	sfw::drawLine(pos.x, pos.y, acc.x, acc.y, CYAN);
	sfw::drawLine(pos.x, pos.y, vel.x, vel.y, YELLOW);
}

void drawAABB(const AABB    &t, unsigned TINT)
{
	sfw::drawLine(t.min().x, t.min().y, t.max().x, t.min().y, TINT);
	sfw::drawLine(t.min().x, t.max().y, t.max().x, t.max().y, TINT);
	sfw::drawLine(t.max().x, t.min().y, t.max().x, t.max().y, TINT);
	sfw::drawLine(t.min().x, t.min().y, t.min().x, t.max().y, TINT);
}

void drawCollider(const Transform &t, const Collider  &c)
{
	drawCircle(t.getGlobalTransform() * c.circle, BLUE);
}

void drawCircle(const Circle    &t, unsigned TINT)
{
	sfw::drawCircle(t.position.x, t.position.y, t.radius, 6, TINT);
}
#include "sfwdraw.h"
#include "crenderutils.h"

using namespace kml;
void kml::drawMatrix(const kml::mat3 &a)
{
	kml::vec2 &pos = a[2].xy;
	kml::vec2 up = pos + a[1].xy;
	kml::vec2 right = pos + a[0].xy;

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);
}

void kml::drawTransform(const kml::Transform &t) { drawMatrix(t.getGlobalTransform() * kml::mat3::scale({ 30,30 })); }

void kml::drawRigidbody(const kml::Transform &t, const kml::Rigidbody &rb)
{
	kml::vec2 pos = t.getpos();
	kml::vec2 acc = pos + rb.acceleration;
	kml::vec2 vel = pos + rb.velocity;

	sfw::drawLine(pos.x, pos.y, acc.x, acc.y, CYAN);
	sfw::drawLine(pos.x, pos.y, vel.x, vel.y, YELLOW);
}

void kml::drawAABB(const kml::AABB    &t, unsigned TINT)
{
	sfw::drawLine(t.min().x, t.min().y, t.max().x, t.min().y, TINT);
	sfw::drawLine(t.min().x, t.max().y, t.max().x, t.max().y, TINT);
	sfw::drawLine(t.max().x, t.min().y, t.max().x, t.max().y, TINT);
	sfw::drawLine(t.min().x, t.min().y, t.min().x, t.max().y, TINT);
}

void kml::drawCollider(const kml::Transform &t, const kml::Collider  &c)
{
	drawCircle(t.getGlobalTransform() * c.circle, BLUE);
}

void kml::drawCircle(const kml::Circle    &t, unsigned TINT)
{
	sfw::drawCircle(t.position.x, t.position.y, t.r, 6, TINT);
}


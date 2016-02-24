#include "sfwdraw.h"
#include "RigidBody.h"
#include "kmath.h"
#include "Shapes.h"
#include "transform.h"
#include "mat4.h"
#include <cassert>

using namespace kml;

void Math_Tests()
{

	vec2 magtest;
	
	magtest.x = 7.0710678118654752440084436210485;
	magtest.y = 7.0710678118654752440084436210485;
	assert(magtest.magnitude() == 10);

	vec2 angletest;
	angletest.x = 0;
	angletest.y = 0;
	assert(angletest.angle() == 0);

	vec2 normalTest;
	normalTest.x = 6;
	normalTest.y = 8;
	normalTest = normalTest.normal();
	assert(normalTest.x == 0.600000024f && normalTest.y == 0.800000012f);

	vec2 perpTest;
	perpTest.x = 5;
	perpTest.y = 3;
	perpTest = perp(perpTest);
	assert(perpTest.y == 5 && perpTest.x == -3);

	vec2 normalizeTest; 
	normalizeTest.x = 6;
	normalizeTest.y = 8;
	normalizeTest = normalizeTest.normalize();
	assert(normalizeTest.x == 0.600000024f && normalizeTest.y == 0.800000012f);
	
	vec2 small;
	small.x = 1;
	small.y = 1;

	vec2 large;
	large.x = 100;
	large.y = 100;

	vec2 minTest;
	minTest = min(small, large);
	assert(minTest.x == 1 && minTest.y == 1);

	vec2 maxTest;
	maxTest = max(small, large);
	assert(maxTest.x == 100 && maxTest.y == 100);

	vec2 lhsTest; vec2 rhsTest;
	lhsTest.x = 5, lhsTest.y = 5, rhsTest.x = 5, rhsTest.y = 5;
	float t = 5.f;
	
	vec2 mixTest;
	mixTest = mix(lhsTest, rhsTest, t);
	//assert (mixTest.x = 5 && mixTest.y = 5);

	vec2 lerpResult = lerp(lhsTest, rhsTest, t);
	assert(lerpResult.x == 5 && lerpResult.y == 5);

	
	assert(dot(lhsTest, rhsTest) == 50);
	
	vec2 totalTest = lhsTest + rhsTest;
	assert(totalTest.x == 10 && totalTest.y == 10);

	vec2 divTest = lhsTest / t;  
	assert(divTest.x == 1 && divTest.y == 1);

	/*mat3 transposeTest.
		(
		1, 2, 3,
		 4,5,6,
		 7,8,9
	 );*/

	mat3 transposeTest;

	 transposeTest.transpose();

	 transposeTest = transposeTest.identity();
}

int main()
{
	Math_Tests();
	
	Circle C = { { 0,1 },{ 2 } };
	AABB j = { { 0,1 },{ 3,4 } };
	mat3 q = mat3::translate({ 1,1 }) * mat3::rotate(3.14159265359 / 2);// */ *Matrix3::scale({ 2,1 });
	q * C;
	q * j;

	sfw::initContext(800, 800, "Test Window");
	sfw::setBackgroundColor(BLACK);
	int handle = sfw::loadTextureMap("./UFO.png");

	Transform transform1, transform2;
	Transform spin;
	
	Rigidbody rigidBody1;
	rigidBody1.drag = .5f;

	mat3 mat;
	//vec2 position({ 400, 400 });
	
	float speed = 300;
	float angularSpeed = 300;
	float x = 400, y = 400, angle = 0;
	
	
	//transform1.setPos(position);

	while (sfw::stepContext())
	{
		//if (sfw::getKey('S')) y -= sfw::getDeltaTime()  * speed;
		//if (sfw::getKey('W')) y += sfw::getDeltaTime()  * speed;
		//if (sfw::getKey('A')) x -= sfw::getDeltaTime()  * speed;
		//if (sfw::getKey('D')) x += sfw::getDeltaTime()  * speed;

		if (sfw::getKey('S')) rigidBody1.addForce(transform1.getUp() * -speed);
		if (sfw::getKey('W'))rigidBody1.addForce(transform1.getUp() * speed);
		if (sfw::getKey('A')) rigidBody1.addForce(transform1.getRight() * -speed);
		if (sfw::getKey('D')) rigidBody1.addForce(transform1.getRight() * speed);
		
		//if (sfw::getKey('Q')) angle += sfw::getDeltaTime() * angularSpeed;
		//if (sfw::getKey('E')) angle -= sfw::getDeltaTime() * angularSpeed;
		if (sfw::getKey('Q')) rigidBody1.addTorque(angularSpeed);
		if (sfw::getKey('E')) rigidBody1.addTorque(-angularSpeed);

		//transform1.setPos({ 400, 400 });
		transform1.setAngle(angle);
		transform1.setScale({ 150, 150 });

		rigidBody1.integrate(&transform1, sfw::getDeltaTime());

		spin.setParent(&transform1);
		spin.setAngle(-sfw::getTime());

		transform2.setParent(&spin);
		transform2.setPos({ .25f, .25f });
		transform2.setScale({ .5f, .5f });
		
		auto m1 = mat3to4(transform1.getGlobalTransform().m, 0.25);
		auto m2 = mat3to4(transform2.getGlobalTransform().m, 0.1);

		mat = mat3::translate({ 300, 300 })
			* mat3::scale({ 10, 10 })
			* mat3::rotate(sfw::getTime());
		auto m3 = mat3to4(mat.m, -0.5);
		

		sfw::drawTextureMatrix(handle, 0, WHITE, m1.m4);
		//sfw::drawTextureMatrix(handle, 0, MAGENTA, m2.m4);
		//sfw::drawTextureMatrix(handle, 0, BLUE, m3.m4);
	}
	sfw::termContext();

	return 0;
}


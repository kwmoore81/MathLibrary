#include "sfwdraw.h"
#include "RigidBody.h"
#include "kmath.h"
#include "Shapes.h"
#include "transform.h"
#include "mat4.h"

using namespace kml;

int main()
{
	//Circle C = { { 0,1 },{ 2 } };
	//AABB j = { { 0,1 },{ 3,4 } };
	//mat3 q = mat3::translate({ 1,1 }) * mat3::rotate(3.14159265359 / 2);// */ *Matrix3::scale({ 2,1 });
	//q * C;
	//q * j;

	sfw::initContext();
	int  handle = sfw::loadTextureMap("./UFO.png");

	Transform transform1, transform2;
	Transform spin;
	
	mat3 mat;
	vec2 position({ 400, 400 });
	Rigidbody rigidBody1;
	rigidBody1.drag = .25f;
	float x = 400, y = 400, angle = 0;
	float speed = 100;
	float angularSpeed = 5;
	
	
	transform1.setPos(position);

	while (sfw::stepContext())
	{
		//if (sfw::getKey('S')) y -= sfw::getDeltaTime()  * speed;
		//if (sfw::getKey('W')) y += sfw::getDeltaTime()  * speed;
		//if (sfw::getKey('A')) x -= sfw::getDeltaTime()  * speed;
		//if (sfw::getKey('D')) x += sfw::getDeltaTime()  * speed;

		if (sfw::getKey('S')) rigidBody1.addForce({ 0, speed });
		if (sfw::getKey('W'))rigidBody1.addForce(transform1.getRight() * speed);
		if (sfw::getKey('A')) rigidBody1.addForce({ -speed, 0 });
		if (sfw::getKey('D')) rigidBody1.addForce({ speed, 0 });
		
		//if (sfw::getKey('Q')) angle += sfw::getDeltaTime() * angularSpeed;
		//if (sfw::getKey('E')) angle -= sfw::getDeltaTime() * angularSpeed;
		if (sfw::getKey('Q')) rigidBody1.addTorque(angularSpeed);
		if (sfw::getKey('E')) rigidBody1.addTorque(-angularSpeed);

		//transform1.setPos({ 400, 400 });
		transform1.setAngle(angle);
		transform1.setScale({ 500, 300 });

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
		sfw::drawTextureMatrix(handle, 0, MAGENTA, m2.m4);
		sfw::drawTextureMatrix(handle, 0, BLUE, m3.m4);
	}
	sfw::termContext();

	return 0;
}
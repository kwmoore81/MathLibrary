#include "sfwdraw.h"
#include "Math.h"
#include "Transform.h"
#include "RigidBody.h"

int main()
{
	sfw::initContext();
	int  handle = sfw::loadTextureMap("./UFO.png");

	Transform transform1, transform2;
	Transform spin;
	
	RigidBody rigidBody1;
	rigidBody1.drag = .25f;
	float x = 400, y = 400, angle = 0;
	float speed = 100;
	float angularSpeed = 5;
	
	while (sfw::stepContext())
	{
		if (sfw::getKey('S')) y -= sfw::getDeltaTime()  * speed;
		//if (sfw::getKey('S')) rigidBody1.addForce({ 0, speed });
		if (sfw::getKey('W')) y += sfw::getDeltaTime()  * speed;
		if (sfw::getKey('A')) x -= sfw::getDeltaTime()  * speed;
		if (sfw::getKey('D')) x += sfw::getDeltaTime()  * speed;
		if (sfw::getKey('Q')) angle += sfw::getDeltaTime() * angularSpeed;
		if (sfw::getKey('E')) angle -= sfw::getDeltaTime() * angularSpeed;

		transform1.setPos({ x, y });
		transform1.setAngle(angle);
		transform1.setScale({ 500, 300 });

		//rigidBody1.intergrate(&transform1, sfw::getDeltaTime());

		spin.setParent(&transform1);
		spin.setAngle(-sfw::getTime());

		transform2.setParent(&spin);
		transform2.setPos({ .25f, .25f });
		transform2.setScale({ .5f, .5f });

		auto m1 = mat3to4(transform1.getGlobalTransform().m);
		auto m2 = mat3to4(transform2.getGlobalTransform().m);

		sfw::drawTextureMatrix(handle, 0, WHITE, m1.m4);

	}
	sfw::termContext();

	return 0;
}
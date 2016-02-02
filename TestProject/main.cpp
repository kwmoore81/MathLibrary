#include "sfwdraw.h"
#include "collision.h"

int main()
{
	sfw::initContext();
	int  handle = sfw::loadTextureMap("./UFO.png");

	float x = 400, y = 400;
	float angle = 0;
	float speed = 100;
	float angularSpeed = 5;
	while (sfw::stepContext())
	{
		if (sfw::getKey('S')) y -= sfw::getDeltaTime()  * speed;
		if (sfw::getKey('W')) y += sfw::getDeltaTime()  * speed;
		if (sfw::getKey('A')) x -= sfw::getDeltaTime()  * speed;
		if (sfw::getKey('D')) x += sfw::getDeltaTime()  * speed;
		if (sfw::getKey('Q')) angle += sfw::getDeltaTime() * angularSpeed;
		if (sfw::getKey('E')) angle -= sfw::getDeltaTime() * angularSpeed;

		mat3 mat = mat3::translate({ x,y })
			* mat3::scale(200)
			* mat3::rotate(angle);

		mat3 mat1 =
			mat3::rotate(-sfw::getTime())
			* mat3::translate({ .25f, .25f })
			* mat3::scale(.5f);

		sfw::drawTextureMatrix(handle, 0, WHITE, mat3to4(mat.m).m4);
		//sfw::drawTextureMatrix(handle, 0, MAGENTA, mat3to4((mat * mat1).m).m4);
	}
	sfw::termContext();

	return 0;
}
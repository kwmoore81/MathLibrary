#include <cassert>
#include "Window.h"
#include "Input.h"
#include "Time.h"
#include "Factory.h"
#include "DebugDraw.h"
#include "RigidbodyDynamics.h"
#include <iostream>
#include "LifetimeSystem.h"
#include "DynamicResolution.h"
#include "CollisionDetection.h"
#include "PlayerFlightSystem.h"
#include "RenderSystem.h"
#include "Assets.h"
using namespace kml;

//void Math_Tests()
//{
//
//	vec2 magtest;
//	
//	magtest.x = 7.0710678118654752440084436210485;
//	magtest.y = 7.0710678118654752440084436210485;
//	assert(magtest.magnitude() == 10);
//
//	vec2 angletest;
//	angletest.x = 0;
//	angletest.y = 0;
//	assert(angletest.angle() == 0);
//
//	vec2 normalTest;
//	normalTest.x = 6;
//	normalTest.y = 8;
//	normalTest = normalTest.normal();
//	assert(normalTest.x == 0.600000024f && normalTest.y == 0.800000012f);
//
//	vec2 perpTest;
//	perpTest.x = 5;
//	perpTest.y = 3;
//	perpTest = perp(perpTest);
//	assert(perpTest.y == 5 && perpTest.x == -3);
//
//	vec2 normalizeTest; 
//	normalizeTest.x = 6;
//	normalizeTest.y = 8;
//	normalizeTest = normalizeTest.normalize();
//	assert(normalizeTest.x == 0.600000024f && normalizeTest.y == 0.800000012f);
//	
//	vec2 small;
//	small.x = 1;
//	small.y = 1;
//
//	vec2 large;
//	large.x = 100;
//	large.y = 100;
//
//	vec2 minTest;
//	minTest = min(small, large);
//	assert(minTest.x == 1 && minTest.y == 1);
//
//	vec2 maxTest;
//	maxTest = max(small, large);
//	assert(maxTest.x == 100 && maxTest.y == 100);
//
//	vec2 lhsTest; vec2 rhsTest;
//	lhsTest.x = 5, lhsTest.y = 5, rhsTest.x = 5, rhsTest.y = 5;
//	float t = 5.f;
//	
//	vec2 mixTest;
//	mixTest = mix(lhsTest, rhsTest, t);
//	//assert (mixTest.x = 5 && mixTest.y = 5);
//
//	vec2 lerpResult = lerp(lhsTest, rhsTest, t);
//	assert(lerpResult.x == 5 && lerpResult.y == 5);
//
//	
//	assert(dot(lhsTest, rhsTest) == 50);
//	
//	vec2 totalTest = lhsTest + rhsTest;
//	assert(totalTest.x == 10 && totalTest.y == 10);
//
//	vec2 divTest = lhsTest / t;  
//	assert(divTest.x == 1 && divTest.y == 1);
//
//	mat3 addTest, subTest;
//	for (int i = 0; i < 6; ++i)
//	{
//		addTest[i];
//		subTest[i];
//	}
//	/*mat3 transposeTest.
//		(
//		1, 2, 3,
//		 4,5,6,
//		 7,8,9
//	 );*/
//
//	mat3 transposeTest;
//
//	 transposeTest.transpose();
//
//	 transposeTest = transposeTest.identity();
//}

int main()
{
	//Math_Tests();
	
	auto &window = Window::instance();
	auto &input = Input::instance();
	auto &time = Time::instance();

	window.init();
	input.init();
	time.init();

	Asset::instance().loadTexture("Slime", "./testSlime.png");
	Asset::instance().loadTexture("Background", "./forestmap.jpg");
	//float ballPosY = 40, ballPosX = 40, ballVelY = 10, ballVelX = 10, ballRad = 400;
	
	auto player = Factory::makePlayer({ 0,0 });
	auto slime1 = Factory::makeBall({ 400,  400 }, { 0 , 0 }, 20, 40);
	player->rigidbody->drag = 2;
	/*auto ball1 = Factory::makeBall({ 40 , 40 }, { 0 , 0 }, 0.4, 40);
	ball1->rigidbody->drag = 1;

	auto ball2 = Factory::makeBall({ 400,  400 }, { 0 , 0 }, 0.4, 40);
	
	CollisionData cd = kml::iTest(ball1->collider->circle , ball2->collider->circle);*/
	
		
	//Factory::makeWall({ 400 , 400 }, { 400, 400 });
	
	//auto f = Factory::makeBall({ 80, 200 }, { 0,100 }, 280, 200);
	
	//f->rigidbody->addTorque(1000);

	DebugDraw debugDraw;
	RigidbodyDynamics rigidbodies;
	LifetimeSystem lifetimes;
	CollisionDetection collisioner;
	DynamicResolution dynamic;
	PlayerFlightSystem flightsystem;
	RenderSystem render;

	/*sfw::setBackgroundColor(BLACK);
	int forestmap = sfw::loadTextureMap("./forestmap.jpg", 1, 1);
	int testSlime = sfw::loadTextureMap("./testSlime.png", 1, 1);*/
	//float angle = 0;
	

		while (window.step())
		{
			input.step();
			time.step();
			
			//sfw::drawTexture(forestmap, 400, 400, 1067, 800, 0, true, 0, WHITE);
			
			flightsystem.step();


			rigidbodies.step();
			lifetimes.step();

			collisioner.step();
			dynamic.step();
			render.step();
			debugDraw.step();
			/*ball1->controller->FORWARD;
			
			ball1->transform->setAngle(angle);
			ball1->transform->setScale({ 50, 50 });

			ball2->transform->setAngle(angle);
			ball2->transform->setScale({ 50, 50 });
			
			ball1->rigidbody->integrate(&ball1->transform, sfw::getDeltaTime());
			auto m1 = mat3to4(ball1->transform->getGlobalTransform().m, 0.25);
			sfw::drawTextureMatrix(testSlime, 0, WHITE, m1.m4);
			
			ball2->rigidbody->integrate(&ball2->transform, sfw::getDeltaTime());
			auto m2 = mat3to4(ball2->transform->getGlobalTransform().m, 0.25);
			sfw::drawTextureMatrix(testSlime, 0, WHITE, m2.m4);
			*/
			
			
			//if (input.getKey(87))//w
			//{
			//	ball1->rigidbody->velocity.y += 5;
			//	if (ball1->rigidbody->velocity.y >= 60)
			//	{
			//		ball1->rigidbody->velocity.y = 60;
			//	}
			//	//ball2->rigidbody->velocity.y = 40;
			//	
			//};
			//
			//if (input.getKey(83))//s
			//{
			//	ball1->rigidbody->velocity.y += -5;
			//	
			//	if (ball1->rigidbody->velocity.y <= -60)
			//	{
			//		ball1->rigidbody->velocity.y = -60;
			//	}
			//	//ball2->rigidbody->velocity.y = -40;
			//};
			//
			//if (input.getKey(65))//a
			//{
			//	ball1->rigidbody->velocity.x += -5;
			//	
			//	if (ball1->rigidbody->velocity.x <= -60)
			//	{
			//		ball1->rigidbody->velocity.x = -60;
			//	}
			//	//ball2->rigidbody->velocity.x = -40;
			//};
		
			//if (input.getKey(68))//d
			//{
			//	ball1->rigidbody->velocity.x  += 5;
			//	
			//	if (ball1->rigidbody->velocity.x >= 60)
			//	{
			//		ball1->rigidbody->velocity.x = 60;
			//	}
			//	//ball2->rigidbody->velocity.x = 40;
			//};
			//
		}
		
		time.term();
		input.term();
		window.term();
}


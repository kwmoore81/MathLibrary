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
#include "sfwdraw.h"
using namespace kml;

int main()
{
	
	auto &window = Window::instance();
	auto &input = Input::instance();
	auto &time = Time::instance();

	window.init();
	input.init();
	time.init();

	Asset::instance().loadTexture("Slime", "./testSlime.png");
	Asset::instance().loadTexture("Background", "./forestmap.jpg");
	int forestmap = sfw::loadTextureMap("./forestmap.jpg", 1, 1);
	
	auto player = Factory::makePlayer({ 0,0 });
	auto slime1 = Factory::makeBall({ 400,  400 }, { 0 , 0 }, 20, 40);
	auto slime2 = Factory::makeBall({ 650,  500 }, { 0 , 0 }, 20, 40);
	auto slime3 = Factory::makeBall({ 700,  400 }, { 0 , 0 }, 20, 40);
	auto slime4 = Factory::makeBall({ 750,  300 }, { 0 , 0 }, 20, 40);
	auto slime5 = Factory::makeBall({ 600,  250 }, { 0 , 0 }, 20, 40);
	auto slime6 = Factory::makeBall({ 200,  350 }, { 0 , 0 }, 20, 40);
	auto tree1 = Factory::makeWall({ 160,70 }, { 1,1 });
	player->rigidbody->drag = 2;
	
	DebugDraw debugDraw;
	RigidbodyDynamics rigidbodies;
	LifetimeSystem lifetimes;
	CollisionDetection collisioner;
	DynamicResolution dynamic;
	PlayerFlightSystem flightsystem;
	RenderSystem render;

		while (window.step())
		{
			input.step();
			time.step();
			
			sfw::drawTexture(forestmap, 400, 400, 1067, 800, 0, true, 0, WHITE);
			
			flightsystem.step();


			rigidbodies.step();
			lifetimes.step();

			collisioner.step();
			dynamic.step();
			render.step();
			debugDraw.step();
			
		}
		
		time.term();
		input.term();
		window.term();
}


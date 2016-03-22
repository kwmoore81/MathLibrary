#pragma once
#include "GCData.h"

/*
Turn left and right
Move forward
*/
namespace kml
{
	class PlayerController : public GCData<PlayerController>
	{
	public:
		char LEFT, RIGHT,
			FORWARD, DOWN;

		float speed, turnSpeed;

		PlayerController() : LEFT('A'), RIGHT('D'),
			FORWARD('W'), DOWN('S'),
			speed(250), turnSpeed(1) {}
	};
}
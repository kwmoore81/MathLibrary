#pragma once
#include "Window.h"

namespace kml
{
	class Time
	{
		bool isInit;
		Time() : isInit(false) { }

	public:
		static Time &instance() { static Time instance; return instance; }

		bool init() { return isInit = Window::instance().isInitialized(); }
		bool step() { INIT_ASSERT(Time); return true; }
		void term() { INIT_ASSERT(Time); }

		bool     isInitialized() { return isInit; }

		float getTotalTime();
		float getDeltaTime();
	};
}
/*
application time
time since last frame
*/
#include "sfwdraw.h"
#include "Time.h"

using namespace kml;

float Time::getTotalTime()
{
	INIT_ASSERT(Time);
	return sfw::getTime();
}

float Time::getDeltaTime()
{
	INIT_ASSERT(Time);
	return sfw::getDeltaTime();
}

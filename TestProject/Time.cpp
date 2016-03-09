#include "sfwdraw.h"
#include "Time.h"

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

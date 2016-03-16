#pragma once
#include "GCData.h"
namespace kml
{
	class Lifecycle : public GCData<Lifecycle>
	{
	public:
		float lifetime;
		float lifespan;

		Lifecycle() : lifetime(0), lifespan(5) {}
	};
}
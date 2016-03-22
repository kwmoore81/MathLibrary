#pragma once
#include "GCData.h"
#include "kmath.h"
#include <string>

namespace kml
{
	class Sprite : public GCData<Sprite>
	{
	public:
		vec2 offset;
		vec2 dimension;
		float   angle;

		std::string assetName;

		Sprite() : offset({ 0,0 }),
			dimension({ 1,1 }),
			angle(0) { }
	};
}
#pragma once
#include <unordered_map>
#include "kmath.h"

namespace kml
{
	class Asset
	{
		Asset() {}
	public:
		// Rows/Cols animations could go in here
		struct Texture { unsigned width, height, _handle; };

		std::unordered_map<std::string, Texture> textures;

		void loadTexture(const std::string &name, const char *path);
		Texture getTexture(const std::string &name);

		void drawTexture(const std::string &name, const mat3 &m = mat3::identity());

		static Asset &instance() { static Asset i; return i; }
	};
}
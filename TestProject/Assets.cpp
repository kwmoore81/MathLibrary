#include "Assets.h"
#include "sfwdraw.h"
#include "Window.h"


namespace kml
{
	struct _mat4 { float m[16]; };

	_mat4 mat3to4(const float *m, float Z)
	{
		return
		{ m[0],m[1], 0, m[2],
			m[3],m[4], 0, m[5],
			0 ,  0 , 1 ,  0,
			m[6],m[7], Z, m[8] };
	}

	void Asset::loadTexture(const std::string & name, const char * path)
	{
		assert(Window::instance().isInitialized() && "Window is not initialized!");

		Texture temp;
		// TODO: Error handling
		temp._handle = sfw::loadTextureMap(path);
		temp.height = sfw::getTextureHeight(temp._handle);
		temp.width = sfw::getTextureWidth(temp._handle);

		textures[name] = temp;
	}

	Asset::Texture Asset::getTexture(const std::string & name) { return textures[name]; }

	void Asset::drawTexture(const std::string & name, const mat3 &m)
	{
		sfw::drawTextureMatrix(getTexture(name)._handle, 0, WHITE, mat3to4(m.m, 0).m);
	}
}
#pragma once
//#include <cmath>

/*
Example memory layouts and data structure designs for math types.
They make heavy use of 'untagged' unions and structures to avoid
the potentially nebulous performance costs, implementation details,
and duplicity of operator overloading.
Esmeralda Salamone, esmes@aie.edu.au, 1/25/2016
For instructional use.
*/
namespace kml
{
	template<size_t RANGE>
	struct tvec
	{
		union
		{
			float v[RANGE];

			struct
			{
				// playing around
				//typename std::enable_if<RANGE >= 1U, float>::type x;
				//typename std::enable_if<RANGE >= 2U, float>::type y;
				//typename std::enable_if<RANGE >= 2U, float>::type z;
				//typename std::enable_if<RANGE >= 2U, float>::type w;
			};
		};

		constexpr size_t size() const { return RANGE; }

		typename std::enable_if<RANGE == 2U, float>::type angle();
	};

}

// Could do stuff like this
//__declspec(align(32)) class vec3 : public tvec<3>
//{
//public:
//	vec3 cross(const vec3 &rhs);
//};
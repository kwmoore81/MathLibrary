#pragma once
#include "vec2.h"
#include "vec3.h"

namespace kml
{
	struct mat3
	{
		mat3() {}
		~mat3() {}
		union
		{
			vec3 c[3];
			float m[9];
			float mm[3][3];
			struct
			{
				union { vec3 c1; vec2 right; };
				union { vec3 c2; vec2 up; };
				union { vec3 c3; vec2 position; };
			};
		
		};
		static mat3 zero();
		vec3 operator[](unsigned idx) const { return c[idx]; }
		vec3 &operator[](unsigned idx) { return c[idx]; }
		
		mat3 transpose() const
		{
			mat3 r;
			r.c[0] = vec3(mm[0][0], mm[1][0], mm[2][0]);
			r.c[1] = vec3(mm[0][1], mm[1][1], mm[2][1]);
			r.c[2] = vec3(mm[0][2], mm[1][2], mm[2][2]);

			return r;
		}
		float determinant(mat3 &a)
		{
			return a.m[0] * a.m[4] * a.m[8] +
				   a.m[1] * a.m[5] * a.m[6] +
				   a.m[2] * a.m[3] * a.m[7] -
				   a.m[2] * a.m[4] * a.m[6] -
				   a.m[1] * a.m[3] * a.m[8] -
				   a.m[0] * a.m[5] * a.m[7];
		}

		//11 = 0  12 = 1  13 = 2
		//21 = 3  22 = 4  23 = 5
		//31 = 6  32 = 7  33 = 8
		mat3 inverse(mat3 &a)
		{
			mat3 r;
			float temp = 1 / determinant(a);

			r.m[0] = a.m[4] * a.m[8] - a.m[5] * a.m[7] * temp;
			r.m[1] = a.m[2] * a.m[7] - a.m[1] * a.m[8] * temp;
			r.m[2] = a.m[1] * a.m[5] - a.m[2] * a.m[4] * temp;
			r.m[3] = a.m[5] * a.m[6] - a.m[3] * a.m[8] * temp;
			r.m[4] = a.m[0] * a.m[8] - a.m[2] * a.m[6] * temp;
			r.m[5] = a.m[2] * a.m[3] - a.m[0] * a.m[5] * temp;
			r.m[6] = a.m[3] * a.m[7] - a.m[4] * a.m[6] * temp;
			r.m[7] = a.m[1] * a.m[6] - a.m[0] * a.m[7] * temp;
			r.m[8] = a.m[0] * a.m[4] - a.m[1] * a.m[3] * temp;

			return r;
		}

		static mat3 identity()
		{
			mat3 r;
			r.c[0] = vec3(1, 0, 0);
			r.c[1] = vec3(0, 1, 0);
			r.c[2] = vec3(0, 0, 1);

			return r;
		}

		static mat3 scale(const vec2 &xy)
		{
			mat3 r = identity();
			r.mm[0][0] = xy.x;
			r.mm[1][1] = xy.y;
			return r;
		}

		static mat3 translate(const vec2 & xy)
		{
			mat3 r = identity();
			r.mm[2][0] = xy.x;
			r.mm[2][1] = xy.y;
			return r;
		}

		static mat3 rotate(float a)
		{
			mat3 r = identity();
			r.c[0] = vec3(cosf(a), sinf(a), 0);
			r.c[1] = vec3(-sinf(a), cosf(a), 0);
			return r;
		}

	};
	

	vec3 operator*(const mat3 &a, const vec3 &b);
	mat3 operator+(const mat3 &a, const mat3 &b);
	mat3 operator-(const mat3 &a, const mat3 &b);
	mat3 operator*(const mat3 &a, const mat3 &b);

	mat3 &operator+=(const mat3 &a, const mat3 &b);
	mat3 &operator-=(const mat3 &a, const mat3 &b);
	mat3 &operator*=(const mat3 &a, const mat3 &b);

}





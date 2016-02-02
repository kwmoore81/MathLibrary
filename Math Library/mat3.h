#pragma once
#include "vec3.h"
#include "vec2.h"

namespace kml
{
	struct mat3
	{
		mat3() {}
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
		mat3 transpose() const
		{
			mat3 r;
			r.c[0] = vec3(mm[0][0], mm[1][0], mm[2][0]);
			r.c[1] = vec3(mm[0][1], mm[1][1], mm[2][1]);
			r.c[2] = vec3(mm[0][2], mm[1][2], mm[2][2]);
			
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

		static mat3 scale(float scale)
		{
			mat3 r = identity();
			r.mm[0][0] = scale;
			r.mm[1][1] = scale;
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
	
	//mat3 operator+(const mat3 &a, const mat3 &b);
	//mat3 operator-(const mat3 &a, const mat3 &b);
	mat3 operator*(const mat3 &a, const mat3 &b);

	//mat3 &operator+=(const mat3 &a, const mat3 &b);
	//mat3 &operator-=(const mat3 &a, const mat3 &b);
	//mat3 &operator*=(const mat3 &a, const mat3 &b);


	//mat3 transpose(const mat3 &a);
	//mat3 inverse(const mat3 &a);

	//mat3 rotate(float a);
	//mat3 translate(const vec2 &xy);
	//mat3 static scale(float scale);
}

mat3 kml::operator*(const mat3 &a, const mat3 &b)
{
	mat3 r, A = a.transpose();

	r.c[0] = vec3(dot(A.c[0], b.c[0]), dot(A.c[1], b.c[0]), dot(A.c[2], b.c[0]));
	r.c[1] = vec3(dot(A.c[0], b.c[1]), dot(A.c[1], b.c[1]), dot(A.c[2], b.c[1]));
	r.c[2] = vec3(dot(A.c[0], b.c[2]), dot(A.c[1], b.c[2]), dot(A.c[2], b.c[2]));
	return r;
}

inline vec3 operator*(const mat3 &a, const vec3 &b)
{
	mat3 A = a.transpose();
	vec3 r;

	r.x = dot(A.c[0], b);
	r.y = dot(A.c[1], b);
	r.z = dot(A.c[2], b);

	return r;
}


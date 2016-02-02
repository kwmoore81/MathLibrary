#pragma once
struct mat4
{
	float m4[16];
};

mat4 mat3to4(float *m)
{
	return
	{ m[0],m[1], 0, m[2],
		m[3],m[4], 0, m[5],
		0 ,  0 , 1 ,  0,
		m[6],m[7], 0, m[8] };
}
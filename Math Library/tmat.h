#pragma once
#include "tvec.h"


template<size_t size> struct tmat
{
	union
	{
		float      m[size*size];
		float     mm[size][size];
		tvec<size> c[size];
	};
	/*
	etc...
	*/
};
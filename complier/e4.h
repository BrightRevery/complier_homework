#pragma once

#include "token.h"

enum type
{
	number,
	variable,
	temp,
	op,
	empty
};

struct vx
{
	type t;
	int c;

	vx() { t = type::empty; c = 0; };
	vx(type ti, int ci) { t = ti; c = ci; };
};

struct e4
{
	token op;
	vx v1;
	vx v2;
	vx r;

	e4(token oi, vx i1, vx i2, vx ri) { op = oi; v1 = i1; v2 = i2; r = ri; };
	e4(int oi, vx i1, vx i2, vx ri) { op = (token)oi; v1 = i1; v2 = i2; r = ri; };
};


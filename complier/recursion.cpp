#pragma once
#include "recursion.h"
#include<string>
using namespace std;


recursion::recursion()
{}

recursion::recursion(const vector<token>& tokens)
{
	t = tokens;
}

int recursion::program()
{
	declaration_list();
	return 0;
}



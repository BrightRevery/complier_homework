#pragma once
#include <vector>


enum token;

class tokenstring
{
public:
	token cur();
	int next();
	int add(token);



	std::vector<token> tokens;
	int index;
};

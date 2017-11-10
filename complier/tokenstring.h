#pragma once
#include <vector>
#include <fstream>

using namespace std;


enum token;

class tokenstring
{
public:
	token cur();
	int next(ifstream);
	int add(token);



	vector<token> tokens;
	int index;

	
};

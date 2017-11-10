#pragma once
#include <vector>
#include <string>

using namespace std;

class string_table
{
public:
	int look(string);
	string operator[](int);

private:
	vector<string> ts;
};



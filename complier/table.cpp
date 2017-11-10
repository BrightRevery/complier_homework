#include "table.h"

int string_table::look(string t)
{
	int i;
	for (i = 0; i < ts.size(); i++)
	{
		if (ts[i] == t)
			return i;
	}
	ts.push_back(t);
	return i;
}

string string_table::operator[](int i)
{
	return ts[i];
}

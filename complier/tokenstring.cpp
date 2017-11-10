#include "tokenstring.h"

token tokenstring::cur()
{
	return tokens[index];
}

int tokenstring::next(ifstream in)
{
	char c;
	int n;
	in >> c >> n;
	//这里加上查江哥的表，确定token的值
	index++;
	return 0;
}

int tokenstring::add(token t)
{
	tokens.push_back(t);
	return 0;
}

#include "tokenstring.h"

tokenstring::tokenstring()
{
	index = 0;
}

tokenstring::tokenstring(ifstream in)
{
	char c;
	int n;
	in >> c >> n;
	//这里查江哥的表
	index = 0;
}

token tokenstring::cur()
{
	return tokens[index];
}

int tokenstring::next()
{
	index++;
	return 0;
}

int tokenstring::add(token t)
{
	tokens.push_back(t);
	return 0;
}

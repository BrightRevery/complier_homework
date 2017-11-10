#include "tokenstring.h"

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

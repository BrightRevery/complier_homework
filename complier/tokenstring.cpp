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
	//������ϲ齭��ı�ȷ��token��ֵ
	index++;
	return 0;
}

int tokenstring::add(token t)
{
	tokens.push_back(t);
	return 0;
}

#pragma once
#include <iostream>
#include "recursion.h"
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

int recursion::declaration_list()
{
	if (t[i] == token::end)
		return 0;
	else
	{
		declaration();
		declaration_list();
		return 0;
	}
}

int recursion::declaration()
{
	type_specifier();
	if (t[i] == token::var)
	{
		//sem.push_back(t[i + 1]);
		i += 2;
	}
	else
	{
		cout << "�������ͺ���Ӧ�ӱ�����" << endl;
		exit(1);
	}


	if (t[i] == token::semicolon)
	{
		var_declaration();
	}
	else
	{
		fun_declaration();
	}

	return 0;
}

int recursion::var_declaration()
{
	if (t[i] == token::semicolon)
	{
		i++;
	}
	else
	{
		cout << "unknown error" << endl;
		exit(2);
	}
	return 0;
}

int recursion::type_specifier()
{
	if (t[i] == token::k_int || t[i] == token::k_void)
	{
		i++;
	}
	else
	{
		cout << "�ⲻ��һ����������" << endl;
		exit(1);
	}
	return 0;
}

int recursion::fun_declaration()
{
	if (t[i] == left_bracket)
	{
		i++;
	}
	else
	{
		cout << "����Ķ���" << endl;
		exit(1);
	}

	params();

	if (t[i] == right_bracket)
	{
		i++;
	}
	else
	{
		cout << "����Ķ���" << endl;
		exit(1);
	}

	compound_stmt();

	return 0;
}

int recursion::params()
{
	if( t[i] == k_void)
	{
		i++
	}
	else
	{
		param_list();
	}
	return 0;
}

int recursion::param_list()
{
	if( t[i] == num)
	{
		i++
		param();

		if (t[i] == comma)
		{
			i++;
		}
		else
		{
			cout << "����ȱ�ٶ���" << endl;
			exit(1);
		}


		param_list();
	}
	else
	{
		//empty
	}
	return 0;
}


int recursion::param()
{
	type_specifier();
	if (t[i] == token::var)
	{
		//sem.push_back(t[i + 1]);
		i += 2;
	}
	else
	{
		cout << "�������ͺ���Ӧ�ӱ�����" << endl;
		exit(1);
	}
	
	return 0;
}



int recursion::compound_stmt()
{
	if (t[i] == left_brace)
	{
		i++;
	}
	else
	{
		cout << "�������Ӧʹ�û�����" << endl;
		exit(1);
	}

	local_declarations();

	statement_list();

	if (t[i] == right_brace)
	{
		i++;
	}
	else
	{
		cout << "�����Ų�ƥ��" << endl;
		exit(1);
	}
}






















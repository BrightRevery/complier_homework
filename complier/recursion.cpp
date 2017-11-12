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

int recursion::start()
{
	program();
	return 0;
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
	if (t[i] == var)
	{
		//sem.push_back(t[i + 1]);
		i += 2;
	}
	else
	{
		cout << "变量类型后面应接变量名" << endl;
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
		cout << "这不是一个变量类型" << endl;
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
		cout << "错误的定义" << endl;
		exit(1);
	}

	params();

	if (t[i] == right_bracket)
	{
		i++;
	}
	else
	{
		cout << "错误的定义" << endl;
		exit(1);
	}

	compound_stmt();

	return 0;
}

int recursion::params()
{
	if (t[i] == k_void)
	{
		i++;
	}
	else
	{
		param_list();
	}
	return 0;
}

int recursion::param_list()
{
	if (t[i] == num)
	{
		i++;
		param();

		if (t[i] == comma)
		{
			i++;
		}
		else
		{
			cout << "参数缺少逗号" << endl;
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
	if (t[i] == var)
	{
		//sem.push_back(t[i + 1]);
		i += 2;
	}
	else
	{
		cout << "变量类型后面应接变量名" << endl;
		exit(1);
	}

	return 0;
}



int recursion::compound_stmt()
{
	if (t[i] == left_curlybrace)
	{
		i++;
	}
	else
	{
		cout << "复合语句应使用花括号" << endl;
		exit(1);
	}

	local_declarations();

	statement_list();

	if (t[i] == right_curlybrace)
	{
		i++;
	}
	else
	{
		cout << "花括号不匹配" << endl;
		exit(1);
	}
}

int recursion::local_declarations()
{
	if (t[i] == k_int || t[i] == k_void)
	{
		var_declaration();
		local_declarations();
	}
	else
	{
		return 0;
	}
	return 0;
}

int recursion::statement_list()
{
	if (t[i] == right_curlybrace)
	{
		return 0;
	}
	else
	{
		statement();
		statement_list();
	}
	return 0;
}

int recursion::statement()
{
	if (t[i] == left_curlybrace)
	{
		compound_stmt();
	}
	else if (t[i] == k_if)
	{
		selection_stmt();
	}
	else if (t[i] == k_while)
	{
		iteration_stmt();
	}
	else if (t[i] == k_return)
	{
		return_stmt();
	}
	else if (t[i] == var)
	{
		expression_stmt();
	}

	else
	{
		cout << "无法识别的语句" << endl;
		exit(1);
	}
	return 0;
}

int recursion::expression_stmt()
{
	expression();

	if (t[i] == semicolon)
	{
		i++;
	}
	else
	{
		cout << "语句结尾错误" << endl;
		exit(1);
	}

	sem.pop_back();
	return 0;
}

int recursion::selection_stmt()
{
	if (t[i] == k_if)
	{
		i++;
	}
	else
	{
		cout << "unknown error" << endl;
		exit(2);
	}

	if (t[i] == left_bracket)
	{
		i++;
	}
	else
	{
		cout << "if后应接条件语句" << endl;
		exit(1);
	}

	expression();

	if (t[i] == right_bracket)
	{
		i++;
	}
	else
	{
		cout << "括号不匹配" << endl;
		exit(1);
	}

	statement();

	if (t[i] == k_else)
	{
		i++;

		statement();
	}
	else
	{
		return 0;
	}
	return 0;
}

int recursion::iteration_stmt()
{
	if (t[i] == k_while)
	{
		i++;
	}
	else
	{
		cout << "unknown error" << endl;
		exit(2);
	}

	if (t[i] == left_bracket)
	{
		i++;
	}
	else
	{
		cout << "while后应接条件语句" << endl;
		exit(1);
	}

	expression();

	if (t[i] == right_bracket)
	{
		i++;
	}
	else
	{
		cout << "括号不匹配" << endl;
		exit(1);
	}

	statement();

	return 0;
}

int recursion::return_stmt()
{
	if (t[i] == k_return)
	{
		i++;
	}
	else
	{
		cout << "unknown error" << endl;
		exit(2);
	}

	if (t[i] == semicolon)
	{
		i++;
		return 0;
	}
	else
	{
		expression();

		if (t[i] == semicolon)
		{
			i++;
			return 0;
		}

		sem.pop_back();
	}
	return 0;
}

int recursion::expression()
{
	left_var();

	if (t[i] == assign)
	{
		i++;
	}
	else
	{
		cout << "无法理解的语句" << endl;
		exit(1);
	}

	simple_expression();

	red_expression();

	return 0;
}

int recursion::left_var()
{
	if (t[i] == var)
	{
		sem.push_back(vx(variable, t[i + 1]));
		i += 2;
	}
	else
	{
		cout << "错误的左值" << endl;
		exit(1);
	}
	return 0;
}

int recursion::simple_expression()
{
	additive_expression();

	if (t[i] == lesseq || t[i] == token::less || t[i] == greatereq || t[i] == greater || t[i] == token::equal || t[i] == n_equal)
	{
		sem.push_back(vx(op, t[i]));
		i++;
	}
	else
	{
		return 0;
	}


	additive_expression();

	reduction();

	return 0;
}

int recursion::additive_expression()
{
	term();

	if (t[i] == add || t[i] == token::minus)
	{
		sem.push_back(vx(op, t[i]));
		i++;
	}
	else
	{
		return 0;
	}

	additive_expression();

	reduction();

	return 0;
}

int recursion::term()
{
	factor();

	if (t[i] == multiply || t[i] == divide)
	{
		sem.push_back(vx(op, t[i]));
		i++;
	}
	else
	{
		return 0;
	}

	term();

	reduction();
	return 0;
}

int recursion::factor()
{
	if (t[i] == left_bracket)
	{
		i++;
		expression();
		if (t[i] == right_bracket)
		{
			return 0;
		}
		else
		{
			cout << "括号不匹配" << endl;
			exit(1);
		}
	}
	else if (t[i] == var)
	{
		sem.push_back(vx(variable, t[i + 1]));
		i += 2;
		return 0;
	}
	else if (t[i] == num)
	{
		sem.push_back(vx(number, t[i + 1]));
		i += 2;
	}
	return 0;
}

int recursion::red_expression()
{
	vx v1 = sem.back();	sem.pop_back();
	vx r = sem.back();
	qt.push_back(e4(token::equal, v1, vx(), r));
	return 0;
}

int recursion::reduction()
{
	vx v2 = sem.back();	sem.pop_back();
	vx op = sem.back();	sem.pop_back();
	vx v1 = sem.back();	sem.pop_back();
	vx r = vx(temp, t_c++);
	sem.push_back(r);
	qt.push_back(e4(op.c, v1, v2, r));
	return 0;
}



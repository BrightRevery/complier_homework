#pragma once
#include <iostream>
#include "recursion.h"
using namespace std;


recursion::recursion(const vector<token>& tokens)
{
	t = tokens;
}

int recursion::run()
{
	program();
	return 0;
}

vector<e4>& recursion::result()
{
	return qt;
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
	bool using_main = false;
	type_specifier();
	if (t[i] == token::var)
	{
		//sem.push_back(t[i + 1]);
		i += 2;
	}
	else if (t[i] == token::k_main && !main_used)
	{
		using_main = true;
		i += 1;
	}
	else
	{
		cout << "变量类型后面应接变量名" << endl;
		exit(1);
	}


	if (t[i] == token::semicolon)
	{
		if (using_main)
		{
			cout << "“main”不能作为变量名" << endl;
			exit(1);
		}
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
	if (t[i] == token::left_bracket)
	{
		i++;
	}
	else
	{
		cout << "错误的定义" << endl;
		exit(1);
	}

	params();

	if (t[i] == token::right_bracket)
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
	if (t[i] == token::k_void)
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
	if (t[i] == token::num)
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
	if (t[i] == token::var)
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
	if (t[i] == token::left_curlybrace)
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

	if (t[i] == token::right_curlybrace)
	{
		i++;
	}
	else
	{
		cout << "花括号不匹配" << endl;
		exit(1);
	}
	return 0;
}

int recursion::local_declarations()
{
	if (t[i] == token::k_int || t[i] == token::k_void)
	{
		type_specifier();

		if (t[i] == token::var)
		{
			i += 2;
		}
		else
		{
			cout << "变量类型后面应接变量名" << endl;
			exit(1);
		}

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
	if (t[i] == token::right_curlybrace)
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
	if (t[i] == token::left_curlybrace)
	{
		compound_stmt();
	}
	else if (t[i] == token::k_if)
	{
		selection_stmt();
	}
	else if (t[i] == token::k_while)
	{
		iteration_stmt();
	}
	else if (t[i] == token::k_return)
	{
		return_stmt();
	}
	else if (t[i] == token::var)
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

	if (t[i] == token::semicolon)
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
	if (t[i] == token::k_if)
	{
		i++;
	}
	else
	{
		cout << "unknown error" << endl;
		exit(2);
	}

	if (t[i] == token::left_bracket)
	{
		i++;
	}
	else
	{
		cout << "if后应接条件语句" << endl;
		exit(1);
	}

	expression();

	if (t[i] == token::right_bracket)
	{
		i++;
	}
	else
	{
		cout << "括号不匹配" << endl;
		exit(1);
	}

	statement();

	if (t[i] == token::k_else)
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
	if (t[i] == token::k_while)
	{
		i++;
	}
	else
	{
		cout << "unknown error" << endl;
		exit(2);
	}

	if (t[i] == token::left_bracket)
	{
		i++;
	}
	else
	{
		cout << "while后应接条件语句" << endl;
		exit(1);
	}

	expression();

	if (t[i] == token::right_bracket)
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
	if (t[i] == token::k_return)
	{
		i++;
	}
	else
	{
		cout << "unknown error" << endl;
		exit(2);
	}

	if (t[i] == token::semicolon)
	{
		i++;
		return 0;
	}
	else
	{
		simple_expression();

		if (t[i] == token::semicolon)
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

	if (t[i] == token::assign)
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
	if (t[i] == token::var)
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

	if (t[i] == token::lesseq || t[i] == token::less || t[i] == token::greatereq || t[i] == token::greater || t[i] == token::equal || t[i] == token::n_equal)
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

	if (t[i] == token::add || t[i] == token::minus)
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

	if (t[i] == token::multiply || t[i] == token::divide)
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
	if (t[i] == token::left_bracket)
	{
		i++;
		expression();
		if (t[i] == token::right_bracket)
		{
			return 0;
		}
		else
		{
			cout << "括号不匹配" << endl;
			exit(1);
		}
	}
	else if (t[i] == token::var)
	{
		sem.push_back(vx(variable, t[i + 1]));
		i += 2;
		return 0;
	}
	else if (t[i] == token::num)
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



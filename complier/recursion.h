#pragma once
#include <vector>
#include "token.h"
#include "e4.h"


using namespace std;


class recursion
{
public:
	//recursion();
	recursion(const vector<token>&);

	int run();//递归下降的入口

private:


	int program();
	int declaration_list();
	int declaration();
	int var_declaration();
	int type_specifier();
	int fun_declaration();
	int params();
	int param_list();
	int param();
	int compound_stmt();
	int local_declarations();
	int statement_list();
	int statement();
	int expression_stmt();
	int selection_stmt();
	int iteration_stmt();
	int return_stmt();
	int expression();
	int left_var();
	int simple_expression();
	int additive_expression();
	int term();
	int factor();
	//int call();
	//int args();
	//int arg_list();


	int red_expression();
	int reduction();




	vector<token>& t = vector<token>();//标识符序列
	vector<vx> sem = vector<vx>();//语义栈
	vector<e4> qt = vector<e4>();//四元式存储

	int i = 0;//当前标识符位置
	int t_c = 0;//临时变量计数
	

	bool main_used = false;//保证main只出现一次
};


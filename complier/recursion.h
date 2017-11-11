#pragma once
#include <vector>

enum token;
class tokenstring;

using namespace std;

class recursion
{
public:
	recursion();
	recursion(const vector<token>&);



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
	int var();
	int simple_expression();
	int relop();
	int additive_expression();
	int addop();
	int term();
	int mulop();
	int factor();
	int call();
	int args();
	int arg_list();


private:
	vector<token>& t = vector<token>();

	
};


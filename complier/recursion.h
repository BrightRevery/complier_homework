#pragma once
enum token;
class tokenstring;



//struct Token {
//	char content[10];
//	int code;
//}token[100];//TOKEN序列数组，用来存放生成的token

class recursion
{
public:
	int static program();
	int static declaration_list();
	int static declaration();
	int static var_declaration();
	int static compound_stmt();
	int static fun_declaration();
	int static params();
	int static param_list();
	int static param();
	int static compound_stmt();
	int static local_declarations();
	int static statement_list();
	int static statement();
	int static expression_stmt();
	int static selection_stmt();
	int static iteration_stmt();
	int static return_stmt();
	int static expression();
	int static var();
	int static simple_expression();
	int static relop();
	int static additive_expression();
	int static addop();
	int static term();
	int static mulop();
	int static factor();
	int static call();
	int static args();
	int static arg_list();

	//Token t;
};
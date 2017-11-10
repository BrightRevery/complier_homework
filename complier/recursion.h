#pragma once
enum token;

struct Token {
	char content[10];
	int code;
}token[100];//TOKEN序列数组，用来存放生成的token

static int ip = 0;

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

	Token t;
}; recursion r;

struct Token {
	char content[10];
	int code;
}token[100];//TOKEN序列数组，用来存放生成的token

int xuhao = 0;//用以记录生成第几个四元式
int jilu = 0;//用以记录第几个中间变量的生成
string siyuanshi[100];//存取四元式字符串数组
string temp1;
string temp2;
//
class Stack
{
public:
	Stack();
	void Push(string b);
	string Pop();
	void Clear();
	string Peek() const;
	bool isEmpty() const;
private:
	string a[100];
	int Top;
}; Stack s;
Stack::Stack()
{
	Top = -1;
}
void Stack::Push(string b)
{
	if (Top == 99)
		return;
	Top++;
	a[Top] = b;
}
string Stack::Pop()
{
	string element;
	//如果栈空，则返回0；
	if (Top == -1)
		return 0;
	element = a[Top];
	Top--;
	return element;
}

void Stack::Clear()
{
	Top = -1;//直接置栈顶指针，没有清空栈
}
string Stack::Peek()const//取栈顶元素
{
	//如果栈为空，则返回0；
	if (Top == -1)
		return 0;
	return a[Top];
}
bool Stack::isEmpty() const
{
	if (Top == -1)
		return true;
	else
		return false;
}



int recursion::program()
{
	int back = 0;
	if(!(token[ip].))
	declaration_list();
	return 0;
}

int recursion::declaration_list()
{
	if (token == int || token == void)
	{
		declaration();
		declaration_list();
	}
	else
		return 0;
}

int recursion::declaration()
{

}

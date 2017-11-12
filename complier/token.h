#pragma once
using namespace std;

enum token
{
	end,//结束标识


	add,
	minus,
	multiply,
	divide,
	equal,//双等号
	assign,//单等号
	greater,//大于
	less,//小于
	greatereq,//大于等于
	lesseq,//小于等于
	dot,//点
	bit_not,//~ 按位非 
	lg_not,//! 非
	extra,//取余
	left_bracket,//左括号
	right_bracket,//右括号
	left_curlybrace,//左花括号
	right_curlybrace,//右花括号
	left_sqbracket,//左方括号
	right_sqbracket,//右方括号
	bit_and,//位与&
	bit_or ,//位或|
	lg_and,//与&&
	lg_or ,//或||
	comma,//逗号
	semicolon,//分号
	colon,//冒号:
	sharp,//尖号^
	hashtag,//井号
	d_quote,//双引号
	quote,//单引号
	backslash,//反斜杠
	no_equal,//不等于
	increase,//++
	decrease,//--

	//c的关键字，这里全部用k_开头
	k_auto, k_double, k_int, k_struct, k_break, k_else, k_long, k_switch, k_case, k_enum, k_register, k_typedef,
	k_char, k_extern, k_return, k_union, k_const, k_float, k_short, k_unsigned, k_continue, k_for, k_signed,
	k_void, k_default, k_goto, k_sizeof, k_volatile, k_do, k_if, k_while, k_static, k_main,



	number,//数字
	var,//变量
	
	ch,//字符
	str,//字符串


};



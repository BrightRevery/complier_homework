#pragma once
using namespace std;

enum token
{
	end,//������ʶ


	add,
	minus,
	multiply,
	divide,
	equal,//˫�Ⱥ�
	assign,//���Ⱥ�
	greater,//����
	less,//С��
	greatereq,//���ڵ���
	lesseq,//С�ڵ���
	dot,//��
	bit_not,//~ ��λ�� 
	lg_not,//! ��
	extra,//ȡ��
	left_bracket,//������
	right_bracket,//������
	left_curlybrace,//������
	right_curlybrace,//�һ�����
	left_sqbracket,//������
	right_sqbracket,//�ҷ�����
	bit_and,//λ��&
	bit_or ,//λ��|
	lg_and,//��&&
	lg_or ,//��||
	comma,//����
	semicolon,//�ֺ�
	colon,//ð��:
	sharp,//���^
	hashtag,//����
	d_quote,//˫����
	quote,//������
	backslash,//��б��
	no_equal,//������
	increase,//++
	decrease,//--

	//c�Ĺؼ��֣�����ȫ����k_��ͷ
	k_auto, k_double, k_int, k_struct, k_break, k_else, k_long, k_switch, k_case, k_enum, k_register, k_typedef,
	k_char, k_extern, k_return, k_union, k_const, k_float, k_short, k_unsigned, k_continue, k_for, k_signed,
	k_void, k_default, k_goto, k_sizeof, k_volatile, k_do, k_if, k_while, k_static, k_main,



	number,//����
	var,//����
	
	ch,//�ַ�
	str,//�ַ���


};



#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

#include "table.h"
#include "token.h"

using namespace std;

bool is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int morphology(ifstream& in, vector<token>& tokens, vector<int>& num_v, string_table& var_t)
{
	token match_KT(char[]);
	char c;
	char word[32];
	int word_count, go_on = 1;
	int state = 0;
	do
	{
		if (go_on)
		{
			if (!in.get(c))
				break;
		}
		else
			go_on = 1;
		switch (state)
		{
		case 0: if (c == ' ' || c == '\n' || c == '\t')
			break;
				else if (is_alpha(c))
				{
					state = 1;
					word[0] = c;
					word_count = 1;
					break;
				}
				else if (is_digit(c))
				{
					state = 3;
					word[0] = c;
					word_count = 1;
					break;
				}
				else if (c == '\'')
				{
					state = 6;
					word[0] = c;
					word_count = 1;
					break;
				}
				else if (c == '\"')
				{
					state = 8;
					word[0] = c;
					word_count = 1;
					break;
				}
				else if (c == '>')
				{
					state = 10;
					break;
				}
				else if (c == '<')
				{
					state = 11;
					break;
				}
				else if (c == '=')
				{
					state = 12;
					break;
				}
				else if (c == '+')
				{
					tokens.push_back(token::add);
					break;
				}
				else if (c == '-')
				{
					tokens.push_back(token::minus);
					break;
				}
				else if (c == '*')
				{
					tokens.push_back(token::multiply);
					break;
				}
				else if (c == '/')
				{
					tokens.push_back(token::divide);
					break;
				}
				else if (c == '{')
				{
					tokens.push_back(token::left_curlybrace);
					break;
				}
				else if (c == '}')
				{
					tokens.push_back(token::right_curlybrace);
					break;
				}
				else if (c == ',')
				{
					tokens.push_back(token::comma);
					break;
				}
				else if (c == ';')
				{
					tokens.push_back(token::semicolon);
					break;
				}
				else if (c == '(')
				{
					tokens.push_back(token::left_bracket);
					break;
				}
				else if (c == ')')
				{
					tokens.push_back(token::right_bracket);
					break;
				}
				else if (c == '[')
				{
					tokens.push_back(token::left_sqbracket);
					break;
				}
				else if (c == ']')
				{
					tokens.push_back(token::right_sqbracket);
					break;
				}
		case 1: if (isalnum(c))
		{
			word[word_count++] = c;
			break;
		}
				else
				{
					word[word_count++] = '\0';
					state = 2;
					go_on = 0;
					break;
				}
		case 2: 
			tokens.push_back(match_KT(word));
			if (match_KT(word) == token::var)
			{
				tokens.push_back((token)var_t.look(word));
			}
			state = 0;
			go_on = 0;
			break;
		case 3: if (is_digit(c))
		{
			word[word_count++] = c;
			break;
		}
				else if (c == '.')
				{
					state = 4;
					word[word_count++] = c;
					break;
				}
		case 4: if (is_digit(c))
		{
			word[word_count++] = c;
			break;
		}
				else
				{
					word[word_count++] = '\0';
					state = 5;
					go_on = 0;
					break;
				}
		case 5: 
			tokens.push_back(token::number);
			tokens.push_back((token)num_v.size());
			num_v.push_back(atoi(word));
			state = 0;
			go_on = 0;
			break;
		case 6: if (c != '\'')
		{
			word[word_count++] = c;
			break;
		}
				else
				{
					word[word_count++] = c;
					word[word_count++] = '\0';
					state = 7;
					go_on = 0;
					break;
				}
		case 7: 
			tokens.push_back(token::ch);
			state = 0;
			break;
		case 8: if (c != '\"')
		{
			word[word_count++] = c;
			break;
		}
				else
				{
					word[word_count++] = c;
					word[word_count++] = '\0';
					state = 9;
					go_on = 0;
					break;
				}
		case 9: 
			tokens.push_back(token::str);
			state = 0;
			break;
		case 10: if (c == '=')
		{
			tokens.push_back(token::greatereq);
			state = 0;
			break;
		}
				 else
				 {
					 tokens.push_back(token::greater);
					 state = 0;
					 go_on = 0;
					 break;
				 }
		case 11: if (c == '=')
		{
			tokens.push_back(token::lesseq);
			state = 0;
			break;
		}
				 else
				 {
					 tokens.push_back(token::less);
					 state = 0;
					 go_on = 0;
					 break;
				 }
		case 12: if (c == '=')
		{
			tokens.push_back(token::equal);
			state = 0;
			break;
		}
				 else
				 {
					 tokens.push_back(token::assign);
					 state = 0;
					 go_on = 0;
					 break;
				 }
		}
	} while (1);
	return 0;
}

token match_KT(char w[])
{
	if (!strcmp(w, "int"))   return k_int;
	if (!strcmp(w, "main"))  return k_main;
	if (!strcmp(w, "void"))  return k_void;
	if (!strcmp(w, "if"))    return k_if;
	if (!strcmp(w, "else"))  return k_else;
	if (!strcmp(w, "while")) return k_while;
	if (!strcmp(w, "do"))    return k_do;
	if (!strcmp(w, "return"))return k_return;
	if (!strcmp(w, "auto"))  return k_auto;
	if (!strcmp(w, "double"))return k_double;
	if (!strcmp(w, "struct"))return k_struct;
	if (!strcmp(w, "break")) return k_break;
	if (!strcmp(w, "else"))  return k_else;
	if (!strcmp(w, "long"))  return k_long;
	if (!strcmp(w, "switch"))return k_switch;
	if (!strcmp(w, "case"))  return k_case;
	if (!strcmp(w, "enum"))  return k_enum;
	if (!strcmp(w, "register"))return k_register;
	if (!strcmp(w, "typedef"))return k_typedef;
	if (!strcmp(w, "char"))  return k_char;
	if (!strcmp(w, "extern"))return k_extern;
	if (!strcmp(w, "union")) return k_union;
	if (!strcmp(w, "const")) return k_const;
	if (!strcmp(w, "float")) return k_float;
	if (!strcmp(w, "short")) return k_short;
	if (!strcmp(w, "unsigned"))return k_unsigned;
	if (!strcmp(w, "continue"))return k_continue;
	if (!strcmp(w, "for"))   return k_for;
	if (!strcmp(w, "signed"))return k_signed;
	if (!strcmp(w, "default"))return k_default;
	if (!strcmp(w, "goto"))  return k_goto;
	if (!strcmp(w, "sizeof"))return k_sizeof;
	if (!strcmp(w, "volatile"))return k_volatile;
	if (!strcmp(w, "static"))return k_static;
	return var;
}
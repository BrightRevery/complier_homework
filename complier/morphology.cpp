#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include "token.h"
#include "table.h"

using namespace std;

int morphology(ifstream& in, vector<token>& tokens, vector<int>& num_v, string_table& var_t)
//{
//	//in.get();
//    return 0;
//}
//
//
//
//
//
//int temp(ifstream in)
{
	token match_KT(char[]);
	char c;
	char word[32];
	int word_count, go_on = 1;
	int state = 0;
	do
	{
		if (go_on)
			in.get(c);
		else
			go_on = 1;
		switch (state)
		{
		case 0: if (c == ' ' || c == '\n' || c == '\t')
			break;
				else if (isalpha(c))
				{
					state = 1;
					word[0] = c;
					word_count = 1;
					break;
				}
				else if (isdigit(c))
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
		case 3: if (isdigit(c))
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
		case 4: if (isdigit(c))
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
	} while (c != EOF);
	return 0;
}



token match_KT(char* w)
{
	if (!strcmp(w, "int"))   return token::k_int;
	if (!strcmp(w, "main"))  return token::k_main;
	if (!strcmp(w, "void"))  return token::k_void;
	if (!strcmp(w, "if"))    return token::k_if;
	if (!strcmp(w, "else"))  return token::k_else;
	if (!strcmp(w, "while")) return token::k_while;
	if (!strcmp(w, "do"))    return token::k_do;
	if (!strcmp(w, "return"))return token::k_return;
	return token::var;
}





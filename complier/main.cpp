#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "table.h"
#include "token.h"

using namespace std;


int morphology(ifstream, vector<token>, vector<int>, table<string>);

int main()
{
	vector<token> tokens;
	vector<int> num_v;
	table<string> var_t;

	ifstream file_in("target.txt");
	ofstream file_out("4e.txt");
	morphology(file_in, tokens, num_v, var_t);


	system("pause");

	return 0;
}

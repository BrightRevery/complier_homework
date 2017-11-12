#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "table.h"
#include "recursion.h"

using namespace std;


int morphology(ifstream&, vector<token>&, vector<int>&, string_table&);

int main()
{
	vector<token> tokens;
	vector<int> num_v;
	string_table var_t;

	ifstream file_in("target.txt");
	ofstream file_out("4e.txt");

	morphology(file_in, tokens, num_v, var_t);
	 
	recursion r(tokens);
	r.run();

	system("pause");

	return 0;
}

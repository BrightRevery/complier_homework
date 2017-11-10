#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "recursion.h"

using namespace std;


int main()
{
	//int morphology();
	ifstream file_in("target.txt");
	ofstream file_out("4e.txt");
	//vector<int> trans;
	//morphology();
	int x;
	if (r.program() == 1)
	{
		cout << "the result of syntax analysis is succeed!" << endl << endl;
	}
	else
	{
		cout << "the result of syntax analysis is error!" << endl;
		return 0;//说明：错误以后不再执行后续工作
	}
	cout << "h,w!";
	system("pause");

	return 0;
}

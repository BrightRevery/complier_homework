#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//int morphology();
	ifstream file_in("target.txt");
	ofstream file_out("4e.txt");
	//vector<int> trans;
	//morphology();
	int x;
	file_in >> x;
	file_out << x;
	system("pause");

	return 0;
}

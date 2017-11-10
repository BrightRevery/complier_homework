#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream file_in("target.txt");
	ofstream file_out("4e.txt");
	int morphology(file_in);


	system("pause");

	return 0;
}

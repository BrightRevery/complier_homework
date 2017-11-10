#pragma once
#include<vector>


template <class T>
class table
{
public:
	int look(T);
	T operator[](int);

private:
	vector<T> ts;
};



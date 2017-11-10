#include "table.h"

template<class T>
int table<T>::look(T t)
{
	for (int i = 0; i < ts.size(); i++)
	{
		if (ts[i] == t)
			return i;
	}
	ts.push_back(t);
	return i;
}

template<class T>
T table<T>::operator[](int i)
{
	return ts[i];
}

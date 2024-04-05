#include <iostream>

#include <string>
#include <sstream>

template<typename T>
void print(const T &elem)
{
	std::cout << elem << std::endl;
}

template<typename T>
void iter(T *array, size_t len, void (*func)(const T &))
{
	for (size_t i = 0; i < len; i++ )
	{
		func(array[i]);
	}
}
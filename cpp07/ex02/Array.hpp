#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

template <typename T>
class Array
{
public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &copy);
	Array& operator=(const Array<T> &copy);
    ~Array();
	T& operator[](const unsigned int index);
	class out_of_rage: public std::exception
	{
        virtual const char* what() const throw(){
            return "Index out of range";
        }
	};
	unsigned int size() const;
private:
	T *_array;
	unsigned int _n;
};

#include "Array.tpp"

#endif
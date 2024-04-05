#include "Array.hpp"


template<typename T>
Array<T>::Array() {
    _array = NULL;
}


template<typename T>
Array<T>::Array(unsigned int n) {
    _array = new T[n];
	_n = n;
}

template<typename T>
Array<T>::Array(const Array<T> &copy) {
	_array = NULL;
	operator=(copy);
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &copy){
	if(_array != NULL)
		delete[]_array;
	_n = copy.size();
	_array = new T[_n];
	for (unsigned int i = 0; i < copy.size() ; i++)
		_array[i] = copy._array[i];
	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete[]_array;
}

template<typename T>
unsigned int	Array<T>::size() const{
	return(_n);
}

template<typename T>
T& Array<T>::operator[](const unsigned int index){
	if(_array == NULL || index >= size() )
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

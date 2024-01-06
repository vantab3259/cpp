#include "Cat.hpp"

Cat::Cat() : Animal(){
	_type = "cat ";
	std::cout << "Cat " << _type << "create" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(){
	_type =  copy.getType();
	std::cout << "Cat " << _type << "create by copy" << std::endl;
	*this = copy;
}
Cat::~Cat()
{
	std::cout << "Cat " << _type << "Deconstructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Assignation operator of " << src._type << " to " << _type << " called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

void Cat::makeSound(void)const
{
	std::cout << _type << ":" << " MIIIAAWWWUUUUU..... " << std::endl;
}

std::string	Cat::getType(void)const
{
	return (this->_type);
}
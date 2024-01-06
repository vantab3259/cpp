#include "Dog.hpp"

Dog::Dog() : Animal(){
	_type = "Dog ";
	std::cout << "Dog " << _type << "create" << std::endl;
}
Dog::Dog(const Dog &copy) : Animal(){
	_type =  copy.getType();
	std::cout << "Dog " << _type << "create by copy" << std::endl;
	*this = copy;
}
Dog::~Dog()
{
	std::cout << "Dog " << _type << "Deconstructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog Assignation operator of " << src._type << " to " << _type << " called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

void Dog::makeSound(void)const
{
	std::cout << _type << ":" << " OUAFF, GRRR.... " << std::endl;
}

std::string	Dog::getType(void)const
{
	return (this->_type);
}
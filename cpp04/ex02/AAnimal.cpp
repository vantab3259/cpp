#include "Animal.hpp"

Animal::Animal() : _type("template"){
	std::cout << "Animal " << _type << " create" << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy.getType()){
	std::cout << "Animal " << _type << " create by copy" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal " << _type << "Deconstructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal Assignation operator of " << src._type << " to " << _type << " called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

void Animal::makeSound(void)const
{
	std::cout << getType() << " animal doesn't make any sound." << std::endl;
}

std::string	Animal::getType(void)const
{
	return (this->_type);
}

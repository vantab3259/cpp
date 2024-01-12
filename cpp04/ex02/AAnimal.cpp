#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("template"){
	std::cout << "AAnimal " << _type << " create" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : _type(copy.getType()){
	std::cout << "AAnimal " << _type << " create by copy" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal " << _type << "Deconstructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	std::cout << "AAnimal Assignation operator of " << src._type << " to " << _type << " called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

void AAnimal::makeSound(void)const
{
	std::cout << getType() << " AAnimal doesn't make any sound." << std::endl;
}

std::string	AAnimal::getType(void)const
{
	return (this->_type);
}

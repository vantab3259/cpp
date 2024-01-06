#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	_type = "WrongCat ";
	std::cout << "WrongCat " << _type << "create" << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(){
	_type =  copy.getType();
	std::cout << "WrongCat " << _type << "create by copy" << std::endl;
	*this = copy;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << _type << "Deconstructor called" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat Assignation operator of " << src._type << " to " << _type << " called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

void WrongCat::makeSound(void)const
{
	std::cout << _type << ":" << " MIIIAAWWWUUUUU..... " << std::endl;
}

std::string	WrongCat::getType(void)const
{
	return (this->_type);
}

#include "Cat.hpp"

Cat::Cat() : Animal(){
	catBrain = new(Brain);
	std::cout << "Brain cat creation" << std::endl;
	_type = "Cat ";
	std::cout << "Cat " << _type << "create" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(){
	std::cout << "Cat " << _type << "create by copy" << std::endl;
	*this = copy;
}
Cat::~Cat()
{
	delete this->catBrain;
	std::cout << "Cat " << _type << "Deconstructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Assignation operator of " << src._type << " to " << _type << " called" << std::endl;
	if (this == &src)
		return *this;
	catBrain = new Brain(*(src.getBrain()));
	this->_type = src._type;
	return *this;
}

void Cat::makeSound(void)const
{
	std::cout << _type << ":" << " MIIIAAWWWUUUUU..... " << std::endl;
}

Brain *Cat::getBrain( void ) const
{
	return (this->catBrain);
}

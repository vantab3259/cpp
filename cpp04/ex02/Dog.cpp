
#include "Dog.hpp"

Dog::Dog() : Animal(){
	DogBrain = new(Brain);
	std::cout << "Brain Dog creation" << std::endl;
	_type = "Dog ";
	std::cout << "Dog " << _type << "create" << std::endl;
}
Dog::Dog(const Dog &copy) : Animal(){

	DogBrain = new Brain(*(copy.getBrain()));
	_type =  copy.getType();
	std::cout << "Dog " << _type << "create by copy" << std::endl;
	*this = copy;
}
Dog::~Dog()
{
	delete this->DogBrain;
	std::cout << "Dog " << _type << "Deconstructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog Assignation operator of " << src._type << " to " << _type << " called" << std::endl;
	if (this == &src)
		return *this;
	DogBrain = new Brain(*(src.getBrain()));
	this->_type = src._type;
	return *this;
}

void Dog::makeSound(void)const
{
	std::cout << _type << ":" << " OUAAFFF GRRRRR...." << std::endl;
}

Brain *Dog::getBrain( void ) const
{
	return (this->DogBrain);
}


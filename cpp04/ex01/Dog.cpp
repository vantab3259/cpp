
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

std::string	Dog::getType(void)const
{
	return (this->_type);
}

Brain *Dog::getBrain( void ) const
{
	return (this->DogBrain);
}

void Dog::compareTo(Dog const & other_dog) const
{
	std::cout << std::endl;
	std::cout << "Now comparing two dogs\n";
	std::cout << "My brain's heap address: " << static_cast<void*>(this->DogBrain) << std::endl;
	std::cout << "Other's heap address: " << static_cast<void*>(other_dog.getBrain()) << std::endl;
	std::cout << std::endl;
	std::cout << "My brain's ideas \t\t | \t\t\t Other brain's ideas\n";
	for (int i = 0; i < 100; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((DogBrain)->getIdeaAddress(0))[i] << "\t\t\t | \t\t\t" << ((other_dog.getBrain())->getIdeaAddress(0))[i] << std::endl;
	std::cout << std::endl;
}

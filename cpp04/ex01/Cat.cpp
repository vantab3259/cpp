#include "Cat.hpp"

Cat::Cat() : Animal(){
	catBrain = new(Brain);
	std::cout << "Brain cat creation" << std::endl;
	_type = "Cat ";
	std::cout << "Cat " << _type << "create" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(){

	catBrain = new Brain(*(copy.getBrain()));
	_type =  copy.getType();
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

std::string	Cat::getType(void)const
{
	return (this->_type);
}

Brain *Cat::getBrain( void ) const
{
	return (this->catBrain);
}

void Cat::compareTo(Cat const & other_Cat) const
{
	std::cout << std::endl;
	std::cout << "Now comparing two Cats\n";
	std::cout << "My brain's heap address: " << static_cast<void*>(this->catBrain) << std::endl;
	std::cout << "Other's heap address: " << static_cast<void*>(other_Cat.getBrain()) << std::endl;
	std::cout << std::endl;
	std::cout << "My brain's ideas \t\t | \t\t\t Other brain's ideas\n";
	for (int i = 0; i < 100; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((catBrain)->getIdeaAddress(0))[i] << "\t\t\t | \t\t\t" << ((other_Cat.getBrain())->getIdeaAddress(0))[i] << std::endl;
	std::cout << std::endl;
}
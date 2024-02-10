#include "Ice.hpp"

Ice::Ice(){
	_type = "ice";
	std::cout << _type << " create" << std::endl;
}

Ice::Ice(const Ice &copy) {
	std::cout << _type << " create by copy" << std::endl;
	*this = copy;
}

Ice::~Ice()
{
	std::cout << _type << "Deconstructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
	std::cout << "Assignation operator of " << src._type << " to " << _type << " called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

std::string	const & Ice::getType() const
{
	return (this->_type);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at" <<  target.getName() << "*" << std::endl;
}

Ice* Ice::clone() const {
	return(new Ice(*this));
}
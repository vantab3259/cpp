#include "Cure.hpp"

Cure::Cure(){
	_type = "cure";
	std::cout << _type << " create" << std::endl;
}

Cure::Cure(const Cure &copy) {
	std::cout <<  _type << " create by copy" << std::endl;
	*this = copy;
}

Cure::~Cure()
{
	std::cout <<  _type << "Deconstructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
	std::cout << "Assignation operator of " << src._type << " to " << _type << " called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

std::string	const & Cure::getType() const
{
	return (this->_type);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals" <<  target.getName() << "’s wounds *" << std::endl;
}
Cure* Cure::clone() const {
	// Cure *neww = new Cure(_type);
	// return(neww);
	return(new Cure(*this));
}

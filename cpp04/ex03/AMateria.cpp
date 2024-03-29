#include "AMateria.hpp"

AMateria::AMateria(): _type("null") {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type):_type(type) {
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy) {
	*this = copy;
	std::cout << "AMateria " << _type << " create by copy" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria " << _type << "Deconstructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	std::cout << "AMateria Assignation operator of " << src._type << " to " << _type << " called" << std::endl;
	if (this == &src)
		return *this;
	this->_next = src._next;
	this->_type = src._type;
	return *this;
}

std::string	const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at" <<  target.getName() << "*" << std::endl;
}
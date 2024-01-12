#include "Fixed.hpp"

Fixed::Fixed(): fixedPoint(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& assigned)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assigned)
	{
		this->fixedPoint = assigned.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits( int const raw){
	std::cout << "SetRawBits member function called" << std::endl;
	fixedPoint = raw;
}

int		Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return(fixedPoint);
}
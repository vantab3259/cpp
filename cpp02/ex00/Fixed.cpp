#include "Fixed.hpp"


Fixed::Fixed(const Fixed& other) : fixedPoint(other.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& assigned)
{
	if (this != &assigned)
	{
		std::cout << "Copy assignment operator called" << std::endl;
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
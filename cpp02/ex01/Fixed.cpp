#include "Fixed.hpp"

Fixed::Fixed(): fixedPoint(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : fixedPoint(other.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int  value) : fixedPoint(value << FRACT) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : fixedPoint(roundf(value * (1 << FRACT))) {
    std::cout << "Float constructor called" << std::endl;
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

float   Fixed::toFloat( void ) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << FRACT );
}

int     Fixed::toInt( void ) const {
    return this->fixedPoint >> FRACT;
}


void	Fixed::setRawBits( int const raw){
	std::cout << "SetRawBits member function called" << std::endl;
	fixedPoint = raw;
}

int		Fixed::getRawBits( void ) const{
	return(fixedPoint);
}


std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}
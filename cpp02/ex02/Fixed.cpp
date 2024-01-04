#include "Fixed.hpp"


Fixed::Fixed(const Fixed& other) : fixedPoint(other.getRawBits()) {}
Fixed::Fixed(int const value) : fixedPoint(value << FRACT) {
}

Fixed::Fixed(float const value) : fixedPoint(roundf(value * (1 << FRACT))) {
}
Fixed& Fixed::operator=(const Fixed& assigned)
{
	if (this != &assigned)
		this->fixedPoint = assigned.getRawBits();
	return *this;
}
bool	Fixed::operator<(const Fixed& other){
	return(getRawBits() < other.getRawBits());
}

bool	Fixed::operator>(const Fixed& other){
	return(getRawBits() > other.getRawBits());
}
bool	Fixed::operator<=(const Fixed& other){
	return(getRawBits() <= other.getRawBits());
}
bool	Fixed::operator>=(const Fixed& other){
	return(getRawBits() >= other.getRawBits());
}
bool	Fixed::operator!=(const Fixed& other){
	return(getRawBits() != other.getRawBits());
}
bool	Fixed::operator==(const Fixed& other){
	return(getRawBits() == other.getRawBits());
}

Fixed   Fixed::operator+( const Fixed &rhs ) {
    return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &rhs ){
    return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &rhs ) {
    return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &rhs ){
    return Fixed( this->toFloat() / rhs.toFloat() );
}

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed&   Fixed::operator++( void ) {
    fixedPoint += 1;
    return *this;
}

Fixed   Fixed::operator++( int ) {
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed& Fixed::operator--( void ) {
	fixedPoint -= 1;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed temp(*this);
	--(*this);
	return temp;

}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}


Fixed::~Fixed(void)
{
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << FRACT );
}

int     Fixed::toInt( void ) const {
    return this->fixedPoint >> FRACT;
}


void	Fixed::setRawBits( int const raw){
	fixedPoint = raw;
}

int		Fixed::getRawBits( void ) const{
	return(fixedPoint);
}


std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}
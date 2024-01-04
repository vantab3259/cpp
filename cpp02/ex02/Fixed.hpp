#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixedPoint;
	static const int FRACT = 8;
public:
	Fixed() : fixedPoint(0) {
        std::cout << "Default constructor called" << std::endl;
    }
	Fixed(const Fixed& copy);
	Fixed(int const value);
	Fixed(float const value);
	Fixed& operator=(const Fixed& other);
	bool operator<(const Fixed& other);
	bool operator>(const Fixed& other);
	bool operator<=(const Fixed& other);
	bool operator>=(const Fixed& other);
	bool operator!=(const Fixed& other);
	bool operator==(const Fixed& other);
    Fixed	operator+( const Fixed &other );
    Fixed	operator-( const Fixed &other );
    Fixed	operator*( const Fixed &other );
    Fixed	operator/( const Fixed &other );

	Fixed&  operator++( void ); // prefix
    Fixed   operator++( int ); // postfix
    Fixed&  operator--( void ); // prefix
    Fixed   operator--( int ); // postfix

    static Fixed& min( Fixed &a, Fixed &b );
    static const Fixed& min( const Fixed &a, const Fixed &b );
    static Fixed& max( Fixed &a, Fixed &b );
    static const Fixed& max( const Fixed &a, const Fixed &b );


	~Fixed();

	float 	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);
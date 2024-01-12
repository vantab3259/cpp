#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixedPoint;
	static const int FRACT = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(int const value);
	Fixed(float const value);
	Fixed& operator=(const Fixed& other);
	
	~Fixed();

	float 	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);
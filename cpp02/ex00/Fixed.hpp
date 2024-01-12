
# include <iostream>

class Fixed
{
private:
	int fixedPoint;
	static const int FRACT = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};




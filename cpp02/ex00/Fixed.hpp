
# include <iostream>

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
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};




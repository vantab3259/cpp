#include "Fixed.hpp"


int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::max(a, b) << "\t\tthe max of a and b\n" << std::endl;
std::cout << Fixed::min(a, b) << "\tthe min of a and b\n" << std::endl;
return 0;
}
#include "Span.hpp"


int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// sp.addNumber(1, 6);
	// sp.addNumber(2, 420);

	// std::cout << sp.getv()[0] << std::endl;
	// std::cout << sp.getv()[1] << std::endl;
	// std::cout << sp.getv()[2] << std::endl;
	// std::cout << sp.getv()[3] << std::endl;
	// std::cout << sp.getv()[4] << std::endl;
	// std::cout << sp.getv()[5] << std::endl;

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	return 0;
}
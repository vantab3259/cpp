#include "Span.hpp"

Span::Span()
{
	v.reserve(0);
}
Span::Span(unsigned int n)
{
	v.reserve(n);
}

Span::Span(Span const & copy)
{
	*this = copy;
}

Span & Span::operator=(Span const & copy)
{
	if(this != &copy)
	{
		v = copy.v;
	}
	return *this;
}

void	Span::addNumber(unsigned int n)
{
	v.push_back(n);
}
void	Span::addNumber(unsigned int n, unsigned int i)
{
	v.insert(v.end(), n, i);
}


std::vector<unsigned int> Span::getv()
{
	return v;
}

unsigned int Span::shortestSpan()
{
	unsigned int span = *(v.begin()+1) - *(v.begin());
	if (v.size() < 2)
		throw std::runtime_error("Cannot calculate span, less than two numbers are present.");
	std::sort(v.begin(), v.end());
	for (std::vector<unsigned int>::iterator it = v.begin()+1; it != v.end(); it++)
	{
		if(span > (*it) - *(it-1))
			span = (*it) - *(it-1);
	}
	return(span);
}

unsigned int Span::longestSpan()
{
	if (v.size() < 2)
		throw std::runtime_error("Cannot calculate span, less than two numbers are present.");
	unsigned int max = *std::max_element(v.begin(), v.end());
	unsigned int min = *std::min_element(v.begin(), v.end());
	return max-min;
}
Span::~Span()
{
}
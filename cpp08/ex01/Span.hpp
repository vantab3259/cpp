#ifndef SPAN_H
# define SPAN_H
#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>


class Span
{
public:
	Span();
    Span(unsigned int n);
    Span(Span const & copy);
	Span &operator=(Span const & copy);
    ~Span();

	void	addNumber(unsigned int n);
	void	addNumber(unsigned int n, unsigned int i);

	unsigned int longestSpan();
	unsigned int shortestSpan();
	std::vector<unsigned int> getv();
private:
	std::vector<unsigned int> v;
};

#endif
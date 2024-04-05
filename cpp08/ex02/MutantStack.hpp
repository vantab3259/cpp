#ifndef MUTANSTACK_H
#define MUTANSTACK_H

#include <stack>
#include <list>
#include <iostream>
#include <iterator>

template< typename T > 
class MutantStack : public std::stack<T>
{
public:

	MutantStack() : std::stack<T>() {};
	MutantStack(const MutantStack& copy) : std::stack<T>(copy){};
	virtual ~MutantStack() {};
	MutantStack &operator=(const MutantStack &op)
	{
		if (this == &op)
			return (*this);
		std::stack<T>::operator=(op);
		return (*this);
	};

	  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

  iterator begin(void) { return (std::stack<T>::c.begin()); }
  iterator end(void) { return (std::stack<T>::c.end()); }
  const_iterator begin(void) const { return (std::stack<T>::c.begin()); }
  const_iterator end(void) const { return (std::stack<T>::c.end()); }
  reverse_iterator rbegin(void) { return (std::stack<T>::c.rbegin()); }
  reverse_iterator rend(void) { return (std::stack<T>::c.rend()); }
  const_reverse_iterator rbegin(void) const { return (std::stack<T>::c.rbegin()); }
  const_reverse_iterator rend(void) const { return (std::stack<T>::c.rend()); }

private:

};

#endif
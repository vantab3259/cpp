#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
protected:

	std::string	_type;

public:

	Cure();
	Cure(const Cure &copy);
	Cure &operator=(const Cure &copy);
	~Cure();

	std::string const & getType() const;
	virtual Cure* clone() const;
	virtual void use(ICharacter& target);

};

#endif
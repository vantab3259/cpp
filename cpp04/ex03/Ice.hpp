#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
protected:

	std::string	_type;

public:

	Ice();
	Ice(const Ice &copy);
	Ice &operator=(const Ice &copy);
	virtual~Ice();

	std::string const & getType() const;
	virtual Ice* clone() const;
	virtual void use(ICharacter& target);

};
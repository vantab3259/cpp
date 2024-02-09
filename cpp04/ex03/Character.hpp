#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

// class AMateria;

class Character : public ICharacter
{
private:
	AMateria			*(_inventory[4]);
	std::string _name;
	AMateria *_trash;

public:
	Character();
	Character(std::string const & name);
	Character(const Character &copy);
	Character &operator=(const Character &copy);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void push_trash(int i, AMateria *to_trash);
};

#endif
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria			*(_inventory[4]);
	std::string _name;
	AMateria *_trash;

public:

	Character(std::string const & name);
	Character(const Character &copy);
	Character &operator=(const Character &copy);
	~Character() {}

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, Character& target);
	void display_trash();
	void display_inventory();
	void push_trash(int i, AMateria *to_trash);
};
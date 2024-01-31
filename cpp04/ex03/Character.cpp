#include "AMateria.hpp"
#include "Character.hpp"

Character::Character(std::string const & name) : ICharacter(), _name(name) {
	std::cout << "Character " << _name << " create" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character &copy) : ICharacter() {
	std::cout << "Character " << _name << " create by copy" << std::endl;
	*this = copy;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "Character " << _name << "Deconstructor called" << std::endl;
}

Character &Character::operator=(const Character &src)
{
	std::cout << "Character Assignation operator of " << src._name << " to " << _name << " called" << std::endl;
	if (this == &src)
		return *this;
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (src._inventory[i])
			this->_inventory[i] = (src._inventory[i])->clone();
	}
	this->_name = src._name;
	return *this;
}

std::string	const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m){
	for(int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
			_inventory[i] = m->clone();
		i++;
	}
}
void Character::unequip(int idx){
	if (idx < 0 || idx >= 4 || !(this->_inventory)[idx])
	{
		std::cout << "Nothing found to use at index " << idx << std::endl;
		return ;
	}
	push_trash(idx, _inventory[idx]);

}

void Character::use(int idx, Character& target) {
	if (idx < 0 || idx >= 4 || !(_inventory)[idx])
	{
		std::cout << "Nothing found to use at index " << idx << std::endl;
		return ;
	}
	std::cout << getName();
	((_inventory)[idx])->use(target);
}

void Character::push_trash(int i, AMateria *to_trash)
{
	AMateria *tmp_trash;
	
	tmp_trash = this->_trash;
	this->_trash = to_trash;
	if (to_trash)
		to_trash->_next = tmp_trash;
	if (i != -1)
		this->_inventory[i] = NULL;
}

void Character::display_inventory()
{
	std::cout << "===============================================" << std::endl;
	std::cout << "Inventory of " << _name << ":" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
			std::cout << i << ". Empty" << std::endl;
		else
			std::cout << i << ". " << _inventory[i]->getType() << std::endl;
	}
	std::cout << "===============================================" << std::endl;
}

void Character::display_trash()
{
	AMateria *tmp = _trash;
	int i = 0;
	
	std::cout << "***********************************************" << std::endl;
	std::cout << "Trash of " << _name << ":" << std::endl;
	while (tmp)
	{
		std::cout << i++ << ". " << tmp->getType() << std::endl;
		tmp = tmp->_next;
	}
	std::cout << "***********************************************" << std::endl;
}

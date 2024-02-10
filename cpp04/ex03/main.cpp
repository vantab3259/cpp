#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	std::cout << "///Information about creation and action of structure///" << std::endl;
	std::cout << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	std::cout << "///Fonction use on 2 index where materia are equiped///"<< std::endl;
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	std::cout << "///End of Fonction use on 2 index where materia are equiped///"<< std::endl;
	std::cout << std::endl;
	std::cout << "///Some more test///"<< std::endl;
	std::cout << std::endl;
	me->unequip(0);
	me->unequip(1);

	std::cout << std::endl;
	std::cout << "///Information about delete of structure///" << std::endl;
	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}
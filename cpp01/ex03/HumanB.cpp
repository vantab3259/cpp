#include "HumanB.hpp"

HumanB::HumanB(){
	if(AFFICHER_MESSAGES == 1)
		std::cout << "Constror : " << name  << std::endl;
}

HumanB::HumanB(std::string name) : name(name), weapon(NULL){
	if(AFFICHER_MESSAGES == 1)
		std::cout << "Constror default : " << name  << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	if(AFFICHER_MESSAGES == 1)
		std::cout << "seter name call with : " << name  << std::endl;
    this->weapon = &weapon;
}

HumanB::~HumanB() {
	if(AFFICHER_MESSAGES == 1)
		std::cout << "destructor default : " << name  << std::endl;
}
    
void	HumanB::attack(){
	if(weapon->getType() == "")
	{
		std::cout << name << " attacks with their hands" << std::endl;
		return;
	}
	std::cout << name << " attacks with their " 
	<< weapon->getType() << std::endl;
}
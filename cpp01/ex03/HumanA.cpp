#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
	if(AFFICHER_MESSAGES == 1)
		std::cout << "Constror : " << name  << std::endl;
}
HumanA::~HumanA(){
	if(AFFICHER_MESSAGES == 1)
		std::cout << "destructor default : " << name  << std::endl;
}
    
void	HumanA::attack(){

	if(weapon.getType() == "")
	{
		std::cout << name << " attacks with their hands" << std::endl;
		return;
	}
	std::cout << name << " attacks with their " 
	<< weapon.getType() << std::endl;

}
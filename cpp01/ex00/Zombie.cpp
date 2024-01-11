#include "Zombie.hpp"

Zombie::Zombie(){
	if(AFFICHER_MESSAGES == 1)
		std::cout << "Constror default : " << name  << std::endl;

}
Zombie::Zombie(std::string name) : name(name){
	if(AFFICHER_MESSAGES == 1)
		std::cout << "Constructeur de : " << this->name <<std::endl;
}

Zombie::~Zombie(){
    std::cout << name << " : destroy" << std::endl;
}

void    Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
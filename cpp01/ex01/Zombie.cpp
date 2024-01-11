#include "Zombie.hpp"


Zombie::Zombie(){
	if(AFFICHER_MESSAGES == 1)
		std::cout << "Constror default : " << name  << std::endl;
}


Zombie::Zombie(std::string name) : name(name){
    if(AFFICHER_MESSAGES == 1)
		std::cout << "Constructor of : " << name  <<std::endl;
}

Zombie::~Zombie(){
    std::cout << name << " : destroy" << std::endl;
}

void    Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::seterName(std::string name){
	if(AFFICHER_MESSAGES == 1)
		std::cout << "seter name call whith : " << name  << std::endl;
    this->name = name;
}

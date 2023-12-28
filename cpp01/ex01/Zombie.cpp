#include "Zombie.hpp"


Zombie::Zombie(){}


Zombie::Zombie(std::string name){
    this->name = name;
}

Zombie::~Zombie(){
    std::cout << name << " : destroy" << std::endl;
}

void    Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::seterName(std::string name){
    this->name = name;
}

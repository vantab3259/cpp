#include "Weapon.hpp"

Weapon::Weapon(){
	if(AFFICHER_MESSAGES == 1)
		std::cout << "Constror default : " << type  << std::endl;
}

Weapon::Weapon(std::string type) : type(type){
	if(AFFICHER_MESSAGES == 1)
		std::cout << "Constror : " << type  << std::endl;
}

Weapon::~Weapon(){
	if(AFFICHER_MESSAGES == 1)
		std::cout << "Destructor default : " << type << std::endl;
}

const std::string&	Weapon::getType() const{
		return(type);
}

void	Weapon::setType(const std::string &type){
	this->type = type;
}
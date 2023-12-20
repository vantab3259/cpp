#include "PhoneBook.hpp"


PhoneBook::PhoneBook( void ) {
    contactCount = 0;
};

PhoneBook::~PhoneBook( void ){};

void PhoneBook::displayContacts() const 
{
	for (int i = 0; i < contactCount; ++i) {
        std::cout << "Contact " << i + 1 << std::endl;
        cellule[i].displayChoice();
        std::cout << std::endl;
    }
}

void PhoneBook::askContact() const
{
	std::string indexStr;
	int index = 9;
	while(index == 9){
		if(contactCount == 0)
		{
			std::cout << "Pas encore de contact enregistré" << std::endl;
			return;
		}
		std::cout << "Choisir l'index du contact a afficher." << std::endl;
		if (!std::getline (std::cin, indexStr) || std::cin.eof()) 
			return;
		if(indexStr.empty())
			continue;
		index = atoi(indexStr.c_str());
		if(index < 0 || index >= contactCount)
		{
			index = 9;
			continue;
		}
		if(index == 0 && indexStr != "0")
		{
			index = 9;
			std::cout << "Entrée invalide" << std::endl;
			continue;
		}
	}
	cellule[index].displayContact();
}
 
void PhoneBook::removeContact( int indexContact ) {
    
    if (indexContact >= 0 && indexContact < contactCount) {
        for (int i = indexContact; i < contactCount - 1; ++i) {
            cellule[i] = cellule[i + 1];
        }
        --contactCount;
    } else {
        std::cout << "Index invalide. Impossible de supprimer le contact." << std::endl;
    }
}

void PhoneBook::addContact( void ) {
    std::string thing[6];
    std::string phrase[5];
    phrase[0] = "Enter first name: ";
    phrase[1] = "Enter last name: ";
    phrase[2] = "Enter nickname: ";
    phrase[3] = "Enter darkest secret: ";
    phrase[4] =  "Enter phone number: ";
    int i = 0;
    if (contactCount >= maxContacts) {
		removeContact(7);
        std::cout << "Le répertoire est plein le dernier contact a ete suprime" << std::endl;
		
	}
	while(i<5){
		std::cout << phrase[i];
		if (!std::getline (std::cin,thing[i]) || std::cin.eof()) {
			return;
		}
		if(thing[i].empty() ||(i == 4 && !isnum(thing[i])))
		{
			std::cout << "Prompt invalide" <<std::endl;
			continue;
		}
		i++;
	}
  	std::stringstream ss;
	ss << contactCount;               


	ss >> thing[5];

	cellule[contactCount].replace(thing);
	++contactCount;
    return;
}

bool PhoneBook::isnum(std::string thing){
	for (int i = 0; i < (int)thing.length() ; i++){
		if(!std::isdigit(thing[i]) && thing[i] != '*' && thing[i] != '#')
			return false;
	}
	return true;
}
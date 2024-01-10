#include "PhoneBook.hpp"


PhoneBook::PhoneBook( void ) : contactCount(0), indexCount(0), contactExist(false) {}

PhoneBook::~PhoneBook( void ){}

void PhoneBook::displayContacts() const 
{
	std::cout << std::setw(10) << "index" << "|" 
			<< std::setw(10) << "First Name" << "|" 
			<< std::setw(10) << "Last Name" << "|" 
			<< std::setw(10) << "Nick Name" << "|" << std::endl;
	for (int i = 0; i < contactCount; ++i) {
        cellule[i].displayChoice();
    }
	std::cout << std::endl;
}

void PhoneBook::askContact() const
{
	std::string indexStr;
	int index = 9;
	while(index == 9){
		if(contactExist == false)
		{
			std::cout << "You do not have any contact yet" << std::endl;
			return;
		}
		std::cout << "Select the index of the contact you want to display : " << std::endl;
		if (!std::getline (std::cin, indexStr) || std::cin.eof()) 
			return;
		for (std::size_t j = 0; j < indexStr.length(); ++j) {
			if (!std::isprint(static_cast<unsigned char>(indexStr[j]))) {
				std::cerr << "Erreur : La ligne contient des caractères non imprimables." << std::endl;
				continue;
			}
		}
		if(indexStr.empty())
			continue;
		index = atoi(indexStr.c_str());
		if(index < 0 || index >= contactCount)
		{
			index = 9;
			std::cout << "Invalid entry" << std::endl;
			continue;
		}
		if(index == 0 && indexStr != "0")
		{
			index = 9;
			std::cout << "Invalid entry" << std::endl;
			continue;
		}
	}
	cellule[index].displayContact();
}

int PhoneBook::addContact( void ) {
	contactExist = true;
    std::string thing[6];
    std::string phrase[5];
    phrase[0] = "Enter first name: ";
    phrase[1] = "Enter last name: ";
    phrase[2] = "Enter nickname: ";
    phrase[3] = "Enter darkest secret: ";
    phrase[4] = "Enter phone number: ";
    int i = 0;
	while(i<5){
		std::cout << phrase[i];
		if (!std::getline (std::cin,thing[i]) || std::cin.eof()) {
			return 0;
		}
		for (std::size_t j = 0; j < thing[i].length(); ++j) {
			if (!std::isprint(static_cast<unsigned char>(thing[i][j]))) {
				std::cerr << "Erreur : La ligne contient des caractères non imprimables." << std::endl;
				return(-1);
			}
		}
		if(thing[i].empty() ||(i == 4 && !isnum(thing[i])))
		{
			std::cout << "Invalid entry" <<std::endl;
			continue;
		}
		i++;
	}
	std::cout << std::endl;
  	std::stringstream ss;
	ss << indexCount;               
	ss >> thing[5];

	cellule[indexCount].replace(thing);
	if(contactCount < maxContacts)
		contactCount++;
	indexCount = (indexCount + 1) % 8;
	return 0;
}

bool PhoneBook::isnum(std::string thing){
	for (int i = 0; i < (int)thing.length() ; i++){
		if(!std::isdigit(thing[i]) && thing[i] != '*' && thing[i] != '#')
			return false;
	}
	return true;
}
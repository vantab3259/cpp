#include "bphone.hpp"

PhoneBook::PhoneBook( void ) {
    contactCount = 0;
};

PhoneBook::~PhoneBook( void ){};

void PhoneBook::displayContacts() const {
    for (int i = 0; i < contactCount; ++i) {
        std::cout << "Contact " << i + 1 << std::endl;
        cellule[i].displayContact();
        std::cout << std::endl;
    }
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
    std::string thing[5];
    std::string phrase[5];
    phrase[0] = "Enter first name: ";
    phrase[1] = "Enter last name: ";
    phrase[2] = "Enter nickname: ";
    phrase[3] = "Enter darkest secret: ";
    phrase[4] =  "Enter phone number: ";
    int i = 0;
    if (contactCount >= maxContacts) {
        std::cout << "Le répertoire est plein. Supprimez un contact existant avant d'en ajouter un nouveau." << std::endl;
    } else {
        while(i<5){
            std::cout << phrase[i];
            std::cin >> thing[i];
            i++;
        }
        ++contactCount;
        cellule[contactCount].replace(thing);
    }
    return;
}
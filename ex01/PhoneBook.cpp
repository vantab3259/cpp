#include "bphone.hpp"

PhoneBook::PhoneBook( void ) {
    contactCount = 0;
};

PhoneBook::~PhoneBook( void ){};

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
    if (contactCount >= maxContacts) {
        std::cout << "Le répertoire est plein. Supprimez un contact existant avant d'en ajouter un nouveau." << std::endl;
    } else {
        std::cout << "Enter first name: ";
        std::cin >> cellule[contactCount].firstName;

        std::cout << "Enter last name: ";
        std::cin >> cellule[contactCount].lastName;

        std::cout << "Enter nickname: ";
        std::cin >> cellule[contactCount].nickName;

        std::cout << "Enter darkest secret: ";
        std::cin >> cellule[contactCount].darkestSecret;

        std::cout << "Enter phone number: ";
        std::cin >> cellule[contactCount].phoneNumber;

        ++contactCount;
    }
}
#include "bphone.hpp"

Contact::Contact( void ){};

Contact::~Contact( void ){};

void Contact::replace(const std::string thing[5]){
   
   
        firstName = thing[0];
        lastName = thing[1];
        nickName = thing[2];
        darkestSecret = thing[3];
        phoneNumber = thing[4];

      

}

void Contact::displayContact() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nick Name: " << nickName << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
}


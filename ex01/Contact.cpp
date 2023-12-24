#include "PhoneBook.hpp"

Contact::Contact( void ){};

Contact::~Contact( void ){};

void Contact::replace(const std::string(& thing)[6]){
		index = std::atoi(thing[5].c_str());
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
    std::cout << std::endl;

}


void Contact::displayChoice() const {
   
	

	std::cout << std::setw(10) << index << "|" 
			<< pointOrNo(firstName, 10) << "|" 
			<< pointOrNo(lastName, 10) << "|" 
			<< pointOrNo(nickName, 10) << "|" << std::endl;
}

std::string Contact::pointOrNo(const std::string& str, size_t width) const {
    std::ostringstream oss; 
    if (str.length() > width) {
        oss << str.substr(0, width - 1) << ".";
    } else {
        oss << std::setw(width) << str;
    }
    return oss.str(); 
}
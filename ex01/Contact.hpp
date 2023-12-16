#pragma once
#include <iostream>
#include <string>
class Contact
{
	public:

		Contact( void );
		~Contact( void );

		void replace(const std::string(& thing)[6]);
		void displayContact() const;
		void displayChoice() const;
		std::string pointOrNo(const std::string& str, size_t width) const;
    	
	private:
		int index;
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string darkestSecret;
		std::string phoneNumber;
};
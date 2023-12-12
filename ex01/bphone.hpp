#pragma once
#include <iostream>
class Contact
{
	public:

		Contact( void );
		~Contact( void );
		void replace(const std::string thing[5]);
		void displayContact() const;
    	
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string darkestSecret;
		std::string phoneNumber;
};

class PhoneBook
{
	public:
		PhoneBook( void );
		~PhoneBook( void );
		void addContact();
		void removeContact(int indexContact);
		void displayContacts() const;

		
	private:
		static const int maxContacts = 8;
		Contact cellule[maxContacts];
		int contactCount;
};
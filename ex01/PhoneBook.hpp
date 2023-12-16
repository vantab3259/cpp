#pragma once
#include <limits>
#include <iostream>
#include "Contact.hpp"
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip> 
#include <sstream>

class PhoneBook
{
	public:
		PhoneBook( void );
		~PhoneBook( void );
		void addContact();
		void removeContact(int indexContact);
		void displayContacts() const;
		void askContact() const;

		
	private:
		static const int maxContacts = 8;
		Contact cellule[maxContacts];
		int contactCount;
};
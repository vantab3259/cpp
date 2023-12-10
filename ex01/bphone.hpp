#include <iostream>
class Contact
{
	public:

		Contact( void );
		~Contact( void );
		void displayContact();


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
		
	private:
		static const int maxContacts = 8;
		Contact cellule[maxContacts];
		int contactCount;
};
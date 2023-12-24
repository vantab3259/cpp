#include "PhoneBook.hpp"



void handleQuitSignal(int signal) {
    (void)signal;
    std::cout << "SIGQUIT signal received. Ignored." << std::endl;
}

int main(void)
{
    PhoneBook phonebook;
    std::string command;
    std::signal(SIGQUIT, handleQuitSignal);
	
    while(true)
    {
        std::cout << "Use : ADD, SEARCH, EXIT for add, search or exit lol" << std::endl;
		if (!std::getline(std::cin, command) || std::cin.eof())
			break;
        if(command == "EXIT")
            break;
        if(command == "ADD")
            phonebook.addContact();
        if(command == "SEARCH")
		{
            phonebook.displayContacts();
			phonebook.askContact();
		}
    }
    return (0);
}
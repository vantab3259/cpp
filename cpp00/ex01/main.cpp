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
		for (std::size_t i = 0; i < command.length(); ++i) {
			if (!std::isprint(static_cast<unsigned char>(command[i]))) {
				std::cerr << "Erreur : La ligne contient des caractères non imprimables." << std::endl;
				continue;
			}
		}
		if(command == "EXIT")
			break;
		if(command == "ADD")
			if(phonebook.addContact())
				break;
		if(command == "SEARCH")
		{
			phonebook.displayContacts();
			phonebook.askContact();
		}
	}
	return (0);
}
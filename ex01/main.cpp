#include "PhoneBook.hpp"



void handleQuitSignal(int signal) {
    (void)signal;
    std::cout << "Signal SIGQUIT reçu. Ignoré." << std::endl;
}
int main(void)
{
    PhoneBook repertoire;
    std::string command;
    std::signal(SIGQUIT, handleQuitSignal);
	std::cout << "ADD,SEARCH,EXIT ae the only available command" << std::endl;
    while(true)
    {
		if (!std::getline(std::cin, command) || std::cin.eof()) {
			return 1;
		}
        if(command == "EXIT")
            break;
        if(command == "ADD")
            repertoire.addContact();
        if(command == "SEARCH")
		{
            repertoire.displayContacts();
			repertoire.askContact();
		}
    }
}
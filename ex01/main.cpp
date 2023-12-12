#include "bphone.hpp"
using namespace std;

int main(void)
{
    PhoneBook repertoire;
    Contact cellule;
    string command;
    while(true)
    {
        getline(cin, command);
        if(command == "EXIT")
            break;
        if(command == "ADD")
            repertoire.addContact();
        if(command == "SEARCH")
            repertoire.displayContacts();
    }
}
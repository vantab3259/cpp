#include <iostream>
#include <string>


#ifndef AFFICHER_MESSAGES
    # define AFFICHER_MESSAGES 0
#endif
class Zombie
{
private:
    std::string name;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

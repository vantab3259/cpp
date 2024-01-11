#include <iostream>
#include <malloc.h>
#include <memory.h>
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
    void seterName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );
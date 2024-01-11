#include "Zombie.hpp"
int main(){
	Zombie noname;
    Zombie *heap = newZombie("hipster");
    Zombie stack("skater");

    randomChump("fonctionnaire");
    stack.announce();
    heap->announce();
    

    delete heap;

}
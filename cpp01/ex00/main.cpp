#include "Zombie.hpp"
int main(){
    Zombie *heap = newZombie("hipster");
    Zombie stack("skater");

    randomChump("fonctionnaire");
    stack.announce();
    heap->announce();
    

    delete heap;

}
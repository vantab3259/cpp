#include "Zombie.hpp"
int main(void){
    int N = 5;
    Zombie * zombies = zombieHorde(N, "soldat");
     for (int i = 0; i < N; i++){
        zombies[i].announce();
    }
    delete [] zombies;
}
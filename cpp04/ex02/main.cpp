
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	// const Animal* k = new Animal();
	// std::cout << k->getType() << " " << std::endl;
	// k->makeSound();
	// delete k;
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 
	j->makeSound();
	delete j;
	delete i;

	

	return 0;
}
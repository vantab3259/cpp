#pragma once

// Includes
#include <string>
#include <iostream>

// classes

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &src);
		void makeSound(void)const;
		std::string getType(void)const;

};
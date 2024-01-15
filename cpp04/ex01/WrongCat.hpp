#pragma once
#include "WrongAnimal.hpp"

// classes

class WrongCat: public WrongAnimal
{
	private:

	public:
		WrongCat();
		WrongCat(const WrongCat &copy);

		~WrongCat();
		WrongCat &operator=(const WrongCat &src);
		void makeSound(void)const;
		std::string getType(void)const;

};
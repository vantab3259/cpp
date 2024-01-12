#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();

		Animal &operator=(const Animal &src);

		virtual void makeSound(void)const;
		std::string getType(void)const;

};

#endif
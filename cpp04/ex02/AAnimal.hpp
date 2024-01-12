#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &src);

		virtual void makeSound(void)const = 0;
		std::string getType(void)const;
};

#endif
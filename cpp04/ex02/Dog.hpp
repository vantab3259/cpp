#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"


class Dog : public Animal
{
	private:
		Brain *DogBrain;
	public:
		Dog();
		Dog(const Dog &copy);
		virtual ~Dog();

		Dog &operator=(const Dog &src);

		virtual void makeSound(void)const;
		Brain *getBrain() const;
};

#endif
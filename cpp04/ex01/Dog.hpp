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
		std::string getType(void)const;
		Brain *getBrain() const;
		void compareTo(Dog const & other_dog) const;
};

#endif
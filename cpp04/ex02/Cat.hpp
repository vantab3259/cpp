#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"


class Cat : public Animal
{
	private:
		Brain *catBrain;
	public:
		Cat();
		Cat(const Cat &copy);
		virtual ~Cat();

		Cat &operator=(const Cat &src);

		virtual void makeSound(void)const;
		std::string getType(void)const;
		Brain *getBrain() const;
		void compareTo(Cat const & other_cat) const;

};

#endif

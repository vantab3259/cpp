
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
private:

public:
	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap(const std::string name);
	~FragTrap(){
		std::cout << "Default destructor Fragtrap called" << std::endl;
	}
	FragTrap& operator=(const FragTrap &src);

	void	highFiveGuys(void);
};


#endif
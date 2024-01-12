
#ifndef SCAVPTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
private:


public:
	ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap(const std::string name);
	~ScavTrap(){
		std::cout << "Default destructor scavtrap called" << std::endl;
	}

	void	attack(const std::string &target);
	void 	guardGate();
};


#endif
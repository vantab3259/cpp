
#ifndef SCAVPTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
private:
	std::string m_name;
	unsigned int hitPoint;
	unsigned int energyPoint;

	unsigned int attackDamage;

public:
	ScavTrap();
	ScavTrap(constScavTrap& other);
	ScavTrap(const std::string& name) ;
	~ScavTrap();

	void	attack(const std::string &target);
	void 	guardGate();
};


#endif
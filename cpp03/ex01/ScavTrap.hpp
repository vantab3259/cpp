
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
	ScavTrap() : ClapTrap("NewPlayer"), m_name("NewPlayer"), hitPoint(100), energyPoint(50), attackDamage(20){
		std::cout << "Constructor default scavtrap NewPlayer called" << std::endl;
	}
	ScavTrap(ScavTrap& other) : ClapTrap(other), m_name(other.getName()), hitPoint(other.getHitPoint()), energyPoint(other.getEnergyPoint()), attackDamage(other.getAttackDammage()){
		std::cout << "Copy coonstructor scavtrap called" << std::endl;
	}
	ScavTrap(const std::string& name) : ClapTrap(name), m_name(name), hitPoint(100), energyPoint(50), attackDamage(20){
		std::cout << "ScavTrap Constructor for the name of scavtrap " << name << " called" << std::endl;
	}
	~ScavTrap(){
		std::cout << "Default destructor scavtrap called" << std::endl;
	}

	void	attack(const std::string &target);
	void 	guardGate();
};


#endif
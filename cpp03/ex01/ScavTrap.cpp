#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("NewPlayer"), m_name("NewPlayer"), hitPoint(100), energyPoint(50), attackDamage(20){
	std::cout << "Constructor default scavtrap NewPlayer called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other), m_name(other.getName()), hitPoint(other.getHitPoint()), energyPoint(other.getEnergyPoint()), attackDamage(other.getAttackDammage()){
	std::cout << "Copy coonstructor scavtrap called" << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), m_name(name), hitPoint(100), energyPoint(50), attackDamage(20){
	std::cout << "ScavTrap Constructor for the name of scavtrap " << name << " called" << std::endl;
}
ScavTrap::~ScavTrap(){
	std::cout << "Default destructor scavtrap" << m_name << "called" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap" << m_name << "is now in Gate keeper mode"<< std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		std::cout << "ScavTrap " << this->m_name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoint--;
	}
	else if (this->energyPoint == 0)
		std::cout << "\033[31mScavTrap " << this->m_name << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl;
	else
		std::cout << "\033[31mScavTrap " << this->m_name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
}
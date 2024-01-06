#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{

	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Constructor for the name " << this->m_name << " called" << std::endl;
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
#include "ScavTrap.hpp"


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
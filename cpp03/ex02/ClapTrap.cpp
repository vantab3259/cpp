#include "ClapTrap.hpp"

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if(this != &other)
	{
		m_name = other.getName();
		hitPoint = other.getHitPoint();
		attackDamage = other.getAttackDammage();
		energyPoint = other.getEnergyPoint();
	}
	return(*this);
}

std::string ClapTrap::getName() const {
	return(m_name);
}

int ClapTrap::getAttackDammage() const {
	return(attackDamage);
}

int ClapTrap::getEnergyPoint() const {
	return(energyPoint);
}

int ClapTrap::getHitPoint() const {
	return(hitPoint);
}

void ClapTrap::attack(const std::string& target){
	if (hitPoint > 0 && energyPoint > 0) {
        std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoint--;
    } else {
        std::cout << "ClapTrap can't attack. Not enough hit points or energy points." << std::endl;
    }

}

void ClapTrap::takeDamage(unsigned int amount){
	if (hitPoint <= amount)
    {
        std::cout << "ClapTrap " << m_name << " is dead!" << std::endl;
        return;
    }
	if (this->hitPoint > amount)
		this->hitPoint -= amount;
	else if (this->hitPoint > 0)
		this->hitPoint = 0;
    std::cout << "ClapTrap " << this->m_name << " was attacked and lost " << amount << " hit points, he now has " << this->hitPoint << " hit points." << std::endl;
   
}

void ClapTrap::beRepaired(unsigned int amount){
	
	if (energyPoint > 9)
	{
        std::cout << "ClapTrap " << m_name << " is maximum energy level" << std::endl;
        return;
    }	
	if (energyPoint <= amount)
    {
        std::cout << "ClapTrap " << m_name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << m_name << " repairs itself for " << amount << " hit points!" << std::endl;
    energyPoint -= 1;
    hitPoint += amount;
}
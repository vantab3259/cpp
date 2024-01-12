#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap{
private:
	std::string m_name;
	unsigned int hitPoint;
	unsigned int energyPoint;
	unsigned int attackDamage;


public:

	ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap(const std::string& name);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& other);
	
	std::string getName() const ;
	int getAttackDammage() const ;
	int getEnergyPoint() const ;
	int getHitPoint() const ;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
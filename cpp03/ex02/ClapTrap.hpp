#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap{
protected:
	std::string m_name;
	unsigned int hitPoint;
	unsigned int energyPoint;
	unsigned int attackDamage;


public:

	ClapTrap() : m_name("NewPlayer"), hitPoint(10), energyPoint(10), attackDamage(0){
		std::cout << "coonstructor default called" << std::endl;
	}
	ClapTrap(const ClapTrap& other) : m_name(other.getName()), hitPoint(other.getHitPoint()), energyPoint(other.getEnergyPoint()), attackDamage(other.getAttackDammage()){
		std::cout << "Copy coonstructor called" << std::endl;
	}
	ClapTrap(const std::string& name) : m_name(name), hitPoint(10), energyPoint(10), attackDamage(0){
		std::cout << "ClapTrap Constructor for the name " << name << " called" << std::endl;
	}
	~ClapTrap(){
		std::cout << "Default destructor called" << std::endl;
	}

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
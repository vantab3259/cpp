#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# ifndef AFFICHER_MESSAGES
    #  define AFFICHER_MESSAGES 0
# endif
class Weapon {
private:
	std::string type;

public:
	Weapon();
	Weapon(std::string type);
	~Weapon();

	const std::string& getType() const;
	void setType(const std::string& type);
};

#endif
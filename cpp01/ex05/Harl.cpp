#include "Harl.hpp"

Harl::Harl(void) { }
 
Harl::~Harl() { }
 
void    Harl::debug(void)     { std::cout << "This is a debug message" << std::endl; }
void    Harl::info(void)      { std::cout << "This is an info message whith a lot of detail" << std::endl; }
void    Harl::warning(void)   { std::cout << "This is a warning message ! ! !" << std::endl; }
void    Harl::error(void)     { std::cout << "This is an error message OMG BE CARREFUL" << std::endl; }
void    Harl::complain( std::string level ) {
	t_func  funcs[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
		(this->*funcs[i])();
}

//le typedef reviens a ecrire:  void (*t_func)(void){&Harl::debug, &....}
#pragma once

#include <iostream>

class Brain{
private:
	std::string *ideas;
public:
	Brain();
	Brain(const Brain& copy);
	virtual ~Brain();
	Brain &operator=(const Brain &src);
	std::string getIdea(size_t i)const;
	std::string *getIdeaAddress(size_t i)const;
};
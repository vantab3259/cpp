#include "Brain.hpp"

Brain::Brain()
{
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Brainy brain";
	std::cout << "A brain has been constructed and filled with ideas\n";
}

Brain::Brain(const Brain& ref)
{
	std::string *ref_ideas = ref.getIdeaAddress(0);
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ref_ideas[i] + " stolen";
	std::cout << "A brain has been copy constructed and stole the other's ideas\n";
}

Brain::~Brain()
{
	delete [] (this->ideas);
	std::cout << "A brain has been destroyed\n";
}

Brain &Brain::operator=(Brain const &other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

std::string	Brain::getIdea(size_t i)const
{
	if (i < 100)
		return(this->ideas[i]);
	else
		return ("\033[33mThere is only 100 ideas per brain.\033[0m");
}

std::string *Brain::getIdeaAddress(size_t i)const
{
		if (i < 100)
		{
			return &(this->ideas[i]);
		}
		else
			return NULL;  
}

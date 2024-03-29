#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (source.materias[i])
			this->materias[i] = source.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source)
{
	
	if (this == &source)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (source.materias[i])
			this->materias[i] = source.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	int items = 0;

	if (m == NULL)
	{
		std::cout << "Bad Materia!" << std::endl;
		return ;
	}
	while (this->materias[items] && items < 4)
	{
		if (this->materias[items] == m) // If same instance
		{
			std::cout << "Already have the EXACT same Materia in Materias!" << std::endl;
			return ;
		}
		items++;
	}	
	if (items == 4)
	{
		std::cout << "Not enough space to store a new Materia!" << std::endl;
		return ;
	}

	this->materias[items] = m;

}
AMateria* MateriaSource::createMateria(std::string const &type)
{
	int i;

	for (i = 4 - 1; i >= 0; i--)
	{
		if (this->materias[i] && this->materias[i]->getType() == type)
			return (this->materias[i]->clone());
	}
	return (NULL);
}

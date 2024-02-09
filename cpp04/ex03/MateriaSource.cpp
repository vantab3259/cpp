#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
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

	this->materias[items] = m->clone();
	std::cout << m << std::endl;
	
	std::cout << materias[items] << std::endl;
	std::cout << materias[items+1] << std::endl;
}
AMateria* MateriaSource::createMateria(std::string const &type)
{
	int i;

	for (i = 4 - 1; i >= 0; i--)
	{
		std::cout << type << " et" << this->materias[0]->getType() << std::endl;
		if (this->materias[i] && this->materias[i]->getType() == type)
			return (this->materias[i]->clone());
	}
	std::cout << "merde" << std::endl;
	return (NULL);
}

void MateriaSource::display_materias()
{
	std::cout << "###############################################" << std::endl;
	std::cout << "Content of Materias:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
			std::cout << i << ". " << this->materias[i]->getType() << std::endl;
		else
			std::cout << i << ". Empty" << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}
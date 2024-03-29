#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materias[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &source);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &source);
		void learnMateria(AMateria* m);
 		AMateria *createMateria(std::string const &type);
};

#endif
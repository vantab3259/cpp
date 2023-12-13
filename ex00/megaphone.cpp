#include <iostream>

//std::cout : affichage standard (en memoire tampon)
//std::cerr : affichage erreur (affichage direct)
//std::clog : journalisation (en memoire tampon)
//std::endl : retour a la ligne + flush


int main(int ac, char **av)
{
	if(ac<= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return(0);
	}

	int j = 1;
	std::string str(av[j]);
	while (j < ac)
	{	
		str = av[j];
		for(int i = 0; i < (int)str.length(); i++)
		{
			std::cout << (char)toupper(str[i]) ;
		}
		std::cout << " ";
		j++;

	}
	std::cout << std::endl;
	return (0);
}
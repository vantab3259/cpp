#include <iostream>

//std::cout : affichage standard (en memoire tampon)
//std::cerr : affichage erreur (affichage direct)
//std::clog : journalisation (en memoire tampon)
//std::endl : retour a la ligne + flush
using namespace std;

int main(int ac, char **av)
{
	if(ac<= 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return(0);
	}

	int j = 1;
	string str(av[j]);
	while (j < ac)
	{	
		str = av[j];
		for(int i = 0; i < (int)str.length(); i++)
		{
			cout << (char)toupper(str[i]) ;
		}
		cout << " ";
		j++;

	}
	cout << endl;
	return (0);
}
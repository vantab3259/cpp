
#include "Bureaucrat.h"
#include <sstream>


int main(void)
{
	int A;
	std::string N;
	std::string G;

	//try your own test but please send valid input;

	std::cout << "find a name no empty for this Bureaucrat please" << std::endl;
	std::cin >> N;
	std::cout << "find a grade betwean 1 and 150 for this Bureaucrat please" << std::endl;
	
	std::cin >> G;
	std::cout << std::endl;

	std::istringstream(G) >> A;


	//start of preliminary test:

	for (int it = 0; N[it] ; it++) 
	{
		if (!std::isprint((N[it])))
			N = "";
	}

	for (int it = 0; G[it] && it < 9 ; it++) 
	{
		if (!std::isdigit(G[it]) || it == 8) {
			std::cout << "Grade initialisation as a negative number because input invalid" << std::endl;
			std::cout << std::endl;
			A = -1;
			break;
		}
	}
	//end of preliminary test;
	std::cout << std::endl;

	try
	{
		Bureaucrat correcteur_creation(N, A);
		std::cout << correcteur_creation;
		correcteur_creation.incrementGrade(2);
		std::cout << correcteur_creation;
		correcteur_creation.incrementGrade();
		std::cout << correcteur_creation;
		correcteur_creation.incrementGrade(0);
		std::cout << correcteur_creation;
	}
	catch(std::exception& ex)
	{
		std::cout << "Error: " << ex.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat	default_creation;
		std::cout << default_creation;
		default_creation.decrementGrade(80);
		std::cout << default_creation;
		std::cout << "this message will be skip by the catch";
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
		try {
		Bureaucrat	good_bureaucrat("intelo", 1);
		std::cout << good_bureaucrat;
		good_bureaucrat.decrementGrade(80);
		std::cout << good_bureaucrat;
		good_bureaucrat.decrementGrade(50);
		std::cout << good_bureaucrat;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

#include "Bureaucrat.h"
#include "Form.h"
#include <sstream>


int main(void)
{

	try
	{
		Bureaucrat bur("name1", 140);
		std::cout << bur;
		Form form("gtfrce", 150, 150);
		std::cout << form;
		bur.signForm(form);
		std::cout << form;
		bur.signForm(form);

		bur.incrementGrade(160);
		std::cout << bur;
		return(0);
	}
	catch(std::exception& ex)
	{
		std::cout << "Error: " << ex.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat	default_creation;
		std::cout << default_creation;
		Form elite("gtfrce", 10, 150);
		std::cout << elite;
		default_creation.signForm(elite);
		std::cout << elite;
		default_creation.decrementGrade(80);
		std::cout << default_creation;
		std::cout << "this message will be skip by the catch";
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat	good_bureaucrat("intelo", 1);
		Form elite("gtfrce", 10, 150);
		std::cout << elite;
		good_bureaucrat.signForm(elite);
		std::cout << elite;
		std::cout << good_bureaucrat;
		good_bureaucrat.decrementGrade(80);
		std::cout << good_bureaucrat;
		good_bureaucrat.decrementGrade(50);
		std::cout << good_bureaucrat;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	Bureaucrat *ptr = new Bureaucrat("new", 1);
	Bureaucrat egal("patick", 130);
	*ptr = egal;
	try{
		std::cout << *ptr;
		ptr->incrementGrade();
		std::cout << *ptr;
	}
	catch(std::exception& e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	delete ptr;

}

#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <sstream>


int main(void)
{
	try
	{
		Bureaucrat bur("name1", 140);
		std::cout << bur;
		PresidentialPardonForm form;
		std::cout << form;
		bur.signForm(form);
		bur.incrementGrade(137);
		bur.signForm(form);
		std::cout << form;
		bur.signForm(form);
		bur.executeForm(form);
		std::cout << bur;
	}
	catch(std::exception& ex)
	{
		std::cout << "Error: " << ex.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat	default_creation("ffff", 1);
		std::cout << default_creation;
		RobotomyRequestForm elite("gettar");
		std::cout << elite;
		default_creation.signForm(elite);
		default_creation.executeForm(elite);
		elite.execute(default_creation);

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
		ShrubberyCreationForm elite;
		std::cout << elite;
		good_bureaucrat.signForm(elite);
		std::cout << elite;
		std::cout << good_bureaucrat;
		elite.execute(good_bureaucrat);
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
		ptr->incrementGrade(200);
		std::cout << *ptr;
	}
	catch(std::exception& e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	delete ptr;

}
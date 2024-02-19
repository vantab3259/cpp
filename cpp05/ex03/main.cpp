#include <string>
#include <iostream>
#include "AForm.h"
#include "Intern.h"
#include "Bureaucrat.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"

int main() {
	Bureaucrat samuel("Samuel", 1);
	Intern vincent;
	AForm* form;

	form = vincent.makeForm("robotomy request", "Bender");
	form->beSigned(samuel);
	form->execute(samuel);
	delete form;

	try {
		form = vincent.makeForm("burger king", "Steve");
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}


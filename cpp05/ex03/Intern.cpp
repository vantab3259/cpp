#include "Intern.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"

Intern::Intern() {}

Intern::Intern(const Intern &source) { (void) source; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &source) {
	if (this == &source)
		return *this;
	return *this;
}

static AForm* ppFormCreator(std::string& target) {
	return new PresidentialPardonForm(target);
}

static AForm* rrFormCreator(std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* scFormCreator(std::string& target) {
	return new ShrubberyCreationForm(target);
}

typedef AForm* (*creators)(std::string& target);

AForm* Intern::makeForm(std::string name, std::string target) {
	std::string types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	creators crea[3] = {ppFormCreator, rrFormCreator, scFormCreator};
	
	for (int i = 0; i < 3; i++) {
		if (name == types[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return crea[i](target);
		}
	}

	throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw(){ return "Unknown Form"; }
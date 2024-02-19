#include <time.h>
#include <cstdlib>
#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "default", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :  AForm("RobotomyRequestForm", target,  72, 45)

{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source) : AForm(source.getName(), source.target, source.getSignGrade(),
	  source.getExecuteGrade()) {}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& source) {
	AForm::operator=(source);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	AForm::checkRequirements(executor);

	std::cout << "BRRRRRR....KKRKRRKRKKRKRKRRRKR" << std::endl;

	srand(time(NULL));
	bool success = rand() & 1;
	
	std::cout << "Robotomy of " << target << (success ? " was a success" : " has failed") << "." << std::endl;
}
#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "default", 25, 5)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :  AForm("RobotomyRequestForm", target,  150, 150)

{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source) : AForm(source.getName(), source.target, source.getSignGrade(),
	  source.getExecuteGrade()) {}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& source) {
	AForm::operator=(source);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}
#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "default", 25, 5)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :  AForm("ShrubberyCreationForm", target,  150, 150)

{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source) : AForm(source.getName(), source.target, source.getSignGrade(),
	  source.getExecuteGrade()) {}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source) {
	AForm::operator=(source);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}
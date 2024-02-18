#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "default", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :  AForm("PresidentialPardonForm", target,  150, 150)

{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source) : AForm(source.getName(), source.target, source.getSignGrade(),
	  source.getExecuteGrade()) {}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& source) {
	AForm::operator=(source);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "default", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :  AForm("PresidentialPardonForm", target,  25, 5)

{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source) : AForm(source.getName(), source.target, source.getSignGrade(),
	  source.getExecuteGrade()) {}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& source) {
	AForm::operator=(source);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	AForm::checkRequirements(executor);

	std::cout << "Zaphod Beeblebrox pardoned " << target << "." << std::endl;
}

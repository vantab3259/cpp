#include "AForm.h"
#include "Bureaucrat.h"

AForm::AForm() : name("AForm"), signGrade(150), executeGrade(150), _signed(false), target("None")
{

}

AForm::AForm(std::string name, std::string target, int signGrade, int executeGrade) : name(name)
, signGrade(signGrade), executeGrade(executeGrade), _signed(false), target(target) {
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade >150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& AForm) : name(AForm.name), signGrade(AForm.signGrade),
	  executeGrade(AForm.executeGrade), _signed(AForm._signed) {}


AForm& AForm::operator=(const AForm& AForm) {
	*const_cast<std::string*>(&name) = AForm.name;
	*const_cast<int*>(&signGrade) = AForm.signGrade;
	*const_cast<int*>(&executeGrade) = AForm.executeGrade;
	_signed = AForm._signed;
	return (*this);
}

AForm::~AForm()
{}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > signGrade)
		throw AForm::GradeTooLowException();
	else if (_signed)
		std::cout << bureaucrat.getName() << " couldn't sign " << name
				  << " because it is already signed." << std::endl;
	else
		_signed = true;
}
std::string AForm::getName() const { return name; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecuteGrade() const { return executeGrade; }
bool AForm::isSigned() const { return _signed; }

const char*	AForm::GradeTooLowException::what() const throw() {
	return "AForm grade too low!";
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "AForm grade too high!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form){
	os << "Form "<< form.getName() << " signed by grade " << form.getSignGrade()
		<< ", executable by grade " << form.getExecuteGrade() << ". I's"
		<< (form.isSigned() ? " " : "not yet " ) << "signed." << std::endl;
	return os;
}
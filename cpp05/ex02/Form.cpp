#include "Form.h"
#include "Bureaucrat.h"

Form::Form() : name("Form"), signGrade(150), executeGrade(150), _signed(false) 
{

}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name)
, signGrade(signGrade), executeGrade(executeGrade), _signed(false) {
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade >150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& form) : name(form.name), signGrade(form.signGrade),
	  executeGrade(form.executeGrade), _signed(form._signed) {}


Form& Form::operator=(const Form& form) {
	*const_cast<std::string*>(&name) = form.name;
	*const_cast<int*>(&signGrade) = form.signGrade;
	*const_cast<int*>(&executeGrade) = form.executeGrade;
	_signed = form._signed;
	return (*this);
}

Form::~Form()
{}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > signGrade)
		throw Form::GradeTooLowException();
	else if (_signed)
		std::cout << bureaucrat.getName() << " couldn't sign " << name
				  << " because it is already signed." << std::endl;
	else
		_signed = true;
}
std::string Form::getName() const { return name; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecuteGrade() const { return executeGrade; }
bool Form::isSigned() const { return _signed; }

const char*	Form::GradeTooLowException::what() const throw() {
	return "Form grade too low!";
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Form grade too high!";
}

std::ostream& operator<<(std::ostream& os, const Form& form){
	os << "Form "<< form.getName() << " signed by grade " << form.getSignGrade()
		<< ", executable by grade " << form.getExecuteGrade() << ". I's"
		<< (form.isSigned() ? " " : "not yet " ) << "signed." << std::endl;
	return os;
}
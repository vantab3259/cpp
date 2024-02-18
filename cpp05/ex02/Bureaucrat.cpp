#include "Bureaucrat.h"
#include "Form.h"

Bureaucrat::Bureaucrat() : name("default"), grade(75)
{

}
Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name), grade(grade) {
	if (name == "")
	 	throw std::invalid_argument("Invalid name. Please enter a printable string.");
	if (grade > 150)
		throw GradeTooHighException();
	if (grade < 1)
		throw GradeTooLowException();
	
}
Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	std::exception error;

	if (grade > 150)
		throw error;
	*this = copy;
	
}

Bureaucrat&	Bureaucrat::operator =(const Bureaucrat& copy) {
	if (this != &copy)
	{
		grade = copy.grade;
		*const_cast<std::string*>(&name) = copy.name;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{

}

void Bureaucrat::signForm(AForm& form) {
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << "." << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << name << " couldn't sign " << form.getName()
				  << " because their grade is too low." << std::endl;
	}
}

const std::string&	Bureaucrat::getName() const {
	return name;
}

int	Bureaucrat::getGrade() const {
	return grade;
}

void	Bureaucrat::incrementGrade(int change) {
	if (grade - change < 1)
		throw GradeTooHighException();
	grade -= change;
}

void	Bureaucrat::decrementGrade(int change) {
	if (grade + change > 150)
		throw GradeTooLowException();
	grade += change;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low!";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high!";
}


std::ostream&	operator<<(std::ostream &o, const Bureaucrat& bureaucrat) {
	o	<< bureaucrat.getName() << ", bureaucrat of grade "
		<< bureaucrat.getGrade() << std::endl;
	return o;
}
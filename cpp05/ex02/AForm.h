#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		const int signGrade;
		const int executeGrade;
		bool _signed;
	
	protected:
		const std::string target;
		void checkRequirements(const Bureaucrat& bureaucrat) const;
		
	public:
		AForm();
		AForm(const AForm& form);
		AForm(std::string name, std::string target, int signGrade, int executeGrade);
		AForm& operator=(const AForm& form);
		~AForm();

		std::string getTarget() const;
		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool isSigned() const;
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
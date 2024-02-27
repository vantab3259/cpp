#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		const int signGrade;
		const int executeGrade;
		bool _signed;

	public:
		Form();
		Form(const Form& form);
		Form(std::string name, int signGrade, int executeGrade);
		Form& operator=(const Form& form);
		~Form();

		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool isSigned() const;

		virtual void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
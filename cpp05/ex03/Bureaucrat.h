#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <stdexcept>
# include <string>

#include "AForm.h"

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat&	operator =(const Bureaucrat& other);
    ~Bureaucrat();

    void    executeForm(AForm const & form);
    const std::string&	getName() const;
	int					getGrade() const;
    void	incrementGrade(int change = 1);
	void	decrementGrade(int change = 1);
	void	signForm(AForm &form);
    class GradeTooLowException: public std::exception {
        virtual const char*	what() const throw();
    };

    class GradeTooHighException: public std::exception {
        virtual const char*	what() const throw();
    };

private:
    std::string const name;
    int grade;

};

std::ostream&	operator<<(std::ostream &o, const Bureaucrat& bureaucrat);

#endif
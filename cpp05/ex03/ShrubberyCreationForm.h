#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#pragma once
#include "AForm.h"


class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& form);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const & executor) const ;
	class WriteException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:

};

#endif
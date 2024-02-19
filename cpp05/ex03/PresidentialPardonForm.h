#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#pragma once
#include "AForm.h"
#include "Bureaucrat.h"

class PresidentialPardonForm : public AForm
{
public:
    	PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& form);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
		~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;

private:

};

#endif
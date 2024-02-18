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

private:

};

#endif
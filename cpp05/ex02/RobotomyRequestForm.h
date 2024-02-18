#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#pragma once
#include "AForm.h"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& form);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
	~RobotomyRequestForm();

private:

};

#endif
#include <fstream>
#include <iostream>
#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "default", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :  AForm("ShrubberyCreationForm", target,  145, 137)

{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source) : AForm(source.getName(), source.target, source.getSignGrade(),
	  source.getExecuteGrade()) {}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source) {
	AForm::operator=(source);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

const char* ShrubberyCreationForm::WriteException::what() const throw() { return "Cannot write to file"; }

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	checkRequirements(executor);

	const std::string filename = this->target + "_shrubbery";
	const std::string tree = 
		"															.\n"
		"									.         ;  \n"
		"			.              .              ;%     ;;\n"   
		"			,           ,                :;%  %;   \n"
		"				:         ;                   :;%;'     .,\n"   
		"	,.        %;     %;            ;        %;'    ,;\n"
		"		;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
		"		%;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
		"		;%;      %;        ;%;        % ;%;  ,%;'\n"
		"			`%;.     ;%;     %;'         `;%%;.%;'\n"
		"			`:;%.    ;%%. %@;        %; ;@%;%'\n"
		"				`:%;.  :;bd%;          %;@%;'\n"
		"				`@%:.  :;%.         ;@@%;'   \n"
		"					`@%.  `;@%.      ;@@%;    \n"     
		"					`@%%. `@%%    ;@@%;        \n"
		"						;@%. :@%%  %@@%;       \n"
		"						%@bd%%%bd%%:;     \n"
		"							#@%%%%%:;;\n"
		"							%@@%%%::;\n"
		"							%@@@%(o);  . '\n"         
		"							%@@@o%;:(.,'   \n"      
		"						`.. %@@@o%::;       \n"  
		"						`)@@@o%::;         \n"
		"							%@@(o)::;       \n" 
		"						.%@@@@%::;         \n"
		"						;%@@@@%::;.         \n" 
		"						;%@@@@%%:;;;. \n"
		"					...;%@@@@@%%:;;;;,..\n";
	std::ofstream out_file(filename.c_str());

	if (out_file.is_open())
	{
		out_file << tree;
		out_file.close();
	}
	else
		throw WriteException();
}
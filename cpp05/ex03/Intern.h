#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "AForm.h"

class Intern {
	public:
		Intern();
		Intern(const Intern &source);
		~Intern();
		Intern &operator=(const Intern &source);

		AForm* makeForm(std::string name, std::string target);

		class UnknownFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
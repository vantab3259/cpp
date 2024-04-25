#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <cctype> 
# include <string>
# include <stack>
# include <sstream>

class RPN
{
public:
	RPN(std::string const & arg);
	RPN(RPN const & copy);
	RPN & operator=(RPN const & copy);
	~RPN();
	bool			verifLine();
	void			rpn();
private:
	RPN();
	std::string _exp;
};


#endif

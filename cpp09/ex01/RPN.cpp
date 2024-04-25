#include "RPN.hpp"

bool RPN::verifLine()
{
	int v = 0;
	for (size_t i = 0; i < _exp.size(); i++){
		if( _exp[i] != '*' && _exp[i] != '+' && 
			_exp[i] != '-' && _exp[i] != '/' && 
			_exp[i] != ' ' && _exp[i] != '\t' && !isdigit(_exp[i]))
			return false;
		if(_exp[i] != ' ' && _exp[i] != '\t')
			v++;
		else
			v = 0;
		if(v > 1)
			return false;
	}
	return true;
}

void	RPN::rpn(){
	std::stringstream ss(_exp);
	std::string tp;
	std::stack<int> st;

	if (!verifLine())
	{
		std::cout << "Error: wrong argument" << std::endl;
		return;
	}
	while(ss >> tp)
	{
		if (isdigit(tp[0]))
		{
			int num;
			std::istringstream(tp) >> num;
			st.push(num);
		}
		else if(st.size() > 1)
		{
			int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            int result;
            if (tp == "+")
                result = num1 + num2;
            else if (tp == "-")
                result = num1 - num2;
            else if (tp == "*")
                result = num1 * num2;
            else if (tp == "/")
			{
				if (num2 == 0)
				{
					std::cout << "Error: impossible calcul : / 0" << std::endl;
					return;
				}
                result = num1 / num2;
			}
            st.push(result);
		}
		else
		{
			std::cout << "Error: impossible calcul" << std::endl;
			return;
		}

	}
	if(st.size() != 1)
	{
		std::cout << "Error: impossible calcul" << std::endl;
		return;
	}
	std::cout << st.top() << std::endl;

}



RPN::RPN(){return;}

RPN::RPN(std::string const & arg): _exp(arg){
	rpn();
}

RPN::RPN(RPN const & arg){
	*this = arg;
}

RPN & RPN::operator=(RPN const & copy){
	(void) copy;
	return (*this);
}
RPN::~RPN(){}


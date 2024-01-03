# include <iostream>
# include <fstream>

class Harl
{
	private:
		void    debug(void);
		void    info(void);
		void    warning(void);
		void    error(void);
	public:
		Harl(void);
		~Harl();

		void    complain(std :: string level);
		typedef void    (Harl :: *ptr_func)(void);
};

typedef void (Harl::*t_func) ( void );
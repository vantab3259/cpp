CPP = c++
NAME = Bureaucrat
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -
SRCS = main.cpp \
		Bureaucrat.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		PresidentialPardonForm.cpp \
		AForm.cpp \
		Intern.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) -o $(NAME) $(OBJS)


%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o *.d

fclean: clean
	rm -f $(NAME)

re: fclean all
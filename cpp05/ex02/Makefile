CPP = c++
NAME = Bureaucrat
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -MMD
SRCS = main.cpp \
		Bureaucrat.cpp \
		Form.cpp

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
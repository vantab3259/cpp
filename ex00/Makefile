CPP = g++
NAME = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = megaphone.cpp


all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) -o $(NAME) $(SRCS)


fclean: 
	rm -f $(NAME)

re: fclean all

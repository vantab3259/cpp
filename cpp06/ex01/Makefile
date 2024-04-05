CPP = c++
NAME = Serializerer
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -MMD
SRCS = main.cpp \
		Serializer.cpp
	

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) -o $(NAME) $(OBJS)
	@echo  "\033[1;32m"Compiled"\033[0m"


%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	@echo  "\033[1;32m"Clean"\033[0m"
	@rm -f *.o *.d

fclean: clean 
	@rm -f $(NAME)

re: fclean all
CPP = c++
NAME = Animal
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -MMD
SRCS = main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		Brain.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) -o $(NAME) $(OBJS)
	if [ ! -d objs ]; then \
		mkdir -p objs; \
	fi
	mv *.o *.d objs


%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f objs/*.o objs/*.d

fclean: clean
	rm -f $(NAME)

re: fclean all
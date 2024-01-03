CPP = g++
NAME = Harl
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -MMD
SRCS = main.cpp \
       Harl.cpp 
	   
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) -o $(NAME) $(OBJS)
	if [ ! -d objs ]; then \
		mkdir -p objs; \
	fi
	mv *.o objs

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f objs/*.o
	rm -f *.d

fclean: clean
	rm -f $(NAME)

re: fclean all
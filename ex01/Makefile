CPP = g++
NAME = PhoneBook
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp \
       Contact.cpp \
       PhoneBook.cpp
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

fclean: clean
	rm -f $(NAME)

re: fclean all

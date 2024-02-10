CPP = c++
NAME = materia
FLAGS =  -std=c++98 -g3 -MMD
SRCS = main.cpp \
		Ice.cpp \
		Cure.cpp \
		MateriaSource.cpp \
		Character.cpp \
		AMateria.cpp


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
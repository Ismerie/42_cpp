NAME = claptrap

CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98 #-pedantic

INCS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

SRCS = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp

OBJ = $(SRCS:.cpp=.o)

%.o: %.cpp ${INCS} Makefile
	${CC} ${FLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
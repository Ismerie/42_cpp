NAME = generate

CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3 #-pedantic

INCLUDES = Base.hpp A.hpp B.hpp C.hpp

SRCS = main.cpp

INCS = $(addprefix includes/,${INCLUDES})
OBJ = $(addprefix srcs/,${SRCS:.cpp=.o})

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
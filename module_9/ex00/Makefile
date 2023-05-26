NAME = btc

CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

INCLUDES = BitcoinExchange.hpp

SRCS = main.cpp BitcoinExchange.cpp

INCS = $(addprefix includes/,${INCLUDES})
OBJ = $(addprefix srcs/,${SRCS:.cpp=.o})

%.o: %.cpp ${INCS} Makefile
	${CC} ${FLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
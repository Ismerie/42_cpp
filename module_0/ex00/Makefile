NAME = megaphone

CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98 #-pedantic

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp Makefile
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
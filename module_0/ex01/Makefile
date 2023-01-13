NAME = phonebook

CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror #-std=c++98 #-pedantic

INCS = PhoneBook.hpp Contact.hpp

SRCS = PhoneBook.class.cpp Contact.class.cpp main.cpp

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
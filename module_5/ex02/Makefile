NAME = bureau

CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98 #-pedantic

INCLUDES = Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

SRCS = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

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
NAME = AForm
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCFILES = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
INCLUDES = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp
OBJFILES = $(SRCFILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	$(CC) $(FLAGS) -o $(NAME) $(OBJFILES)

%.o: %.cpp $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

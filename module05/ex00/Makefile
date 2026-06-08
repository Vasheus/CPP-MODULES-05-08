NAME = Bureaucrat
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCFILES = main.cpp Bureaucrat.cpp
OBJFILES = $(SRCFILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	$(CC) $(FLAGS) -o $(NAME) $(OBJFILES)

%.o: %.cpp Bureaucrat.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

NAME = convert
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98
SRCFILES = main.cpp ScalarConverter.cpp
OBJFILES = $(SRCFILES:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJFILES)
	$(CC) $(FLAGS) $(SRCFILES) -o $(NAME)

%.o: %.cpp ScalarConverter.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
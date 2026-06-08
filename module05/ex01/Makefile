NAME = Form
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCFILES = main.cpp Bureaucrat.cpp Form.cpp
OBJFILES = $(SRCFILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	$(CC) $(FLAGS) -o $(NAME) $(OBJFILES)

%.o: %.cpp Bureaucrat.hpp Form.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

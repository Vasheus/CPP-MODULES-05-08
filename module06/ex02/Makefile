NAME = RealType
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98
SRCFILES = main.cpp A.cpp B.cpp C.cpp Base.cpp Identify.cpp
OBJFILES = $(SRCFILES:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJFILES)
	$(CC) $(FLAGS) $(SRCFILES) -o $(NAME)

%.o: %.cpp A.hpp B.hpp C.hpp Identify.hpp Base.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
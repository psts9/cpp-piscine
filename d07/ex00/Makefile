NAME = whatever

FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

SRC = whatever.cpp

all: $(NAME)

$(NAME): $(SRC)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
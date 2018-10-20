NAME = cato9tails

FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

SRC = main.cpp

HDR = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

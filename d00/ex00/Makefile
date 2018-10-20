NAME = megaphone

FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

SRC = megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

NAME = eval_expr

FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

SRC = evalexpr.cpp \
	  Fixed.cpp \
	  tokenizer.cpp \
	  validCheck.cpp \
	  equationSolver.cpp

HDR = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME);

re: fclean all

NAME = ft_retro

FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors -lncurses -Iincludes

SRC = src/main.cpp \
	  src/Game.cpp \
	  src/Vec2.cpp \
	  src/GameEntity.cpp \
	  src/Player.cpp \
	  src/Screen.cpp \
	  src/KeyHandler.cpp \
	  src/Scene.cpp \
	  src/Projectile.cpp \
	  src/Enemy.cpp \
	  src/Spawner.cpp

HDR = $(wildcard includes/*.hpp)

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all;

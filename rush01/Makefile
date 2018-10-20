NAME = ft_gkrellm

FLAGS = -Wall -Werror -Wextra -Iinclude -lncurses -Llib -lsfml-graphics -lsfml-window -lsfml-system

SRC = src/main.cpp \
	  src/HostnameModule.cpp \
	  src/OSInfoModule.cpp \
	  src/DatetimeModule.cpp \
	  src/CPUModule.cpp \
	  src/RAMModule.cpp \
	  src/NetworkModule.cpp \
	  src/IMonitorModule.cpp \
	  src/IMonitorDisplay.cpp \
	  src/TextDisplay.cpp \
	  src/GraphicalDisplay.cpp

HDR = $(wildcard include/*.hpp)

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	clang++ $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

#include <cstdlib>
#include <time.h>

#include "Game.hpp"

int main(void)
{
	Game game(30);

	srand(time(NULL));

	game.run();
	game.exit();

	return (0);
}

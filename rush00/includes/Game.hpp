#ifndef GAME_H
# define GAME_H

# include <curses.h>
# include <string>

# include "Screen.hpp"
# include "KeyHandler.hpp"
# include "Scene.hpp"

class Game
{
public:
	Game(void);
	Game(int fps);
	~Game(void);

	void	run(void);
	void	exit(void);

	int	getFPS(void) const;
	int	getRunTime(void) const;

	void	update(void);
	void	displayScene(void);

private:
	Game(Game const& game);
	Game& operator=(Game const& game);

	void	init(void);
	void	start(void);
	void	gameOver(void);

	int		time_;
	bool	running_;
	bool	softexit_;
	bool	init_;
	const int	 fps_;
	unsigned int mspf_;

	Screen*		screen_;
	KeyHandler*	keyHandler_;
	Scene*		scene_;
};

#endif

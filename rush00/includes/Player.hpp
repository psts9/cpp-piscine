#ifndef PLAYER_H
# define PLAYER_H

# include "KeyHandler.hpp"
# include "GameEntity.hpp"
# include "Scene.hpp"
# include "Game.hpp"

class Player : public GameEntity
{
public:
	Player(int x, int y, int c, KeyHandler* handler, Scene* scene, Game* game);
	~Player(void);

	void	update(void);

	int	getLives(void) const;

private:
	Player(void);
	Player(Player const& player);

	void	init(int x, int y, int c, int col1, int col2, KeyHandler* handler, Scene* scene, Game* game);

	void	fire(void);

	KeyHandler* keyHandler_;
	Game*		game_;

	int lives_;
};

#endif

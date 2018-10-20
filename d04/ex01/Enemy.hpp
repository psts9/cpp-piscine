#ifndef ENEMY_H
# define ENEMY_H

# include <string>

class Enemy
{
public:
	Enemy(int hp, std::string const& type);
	Enemy(Enemy const& enemy);
	virtual ~Enemy(void);

	Enemy& operator=(Enemy const& enemy);

	std::string const&	getType(void) const;
	int					getHP(void) const;

	virtual void takeDamage(int amount);

protected:
	std::string type_;
	int hp_;

private:
	Enemy(void);

};

#endif

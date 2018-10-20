#ifndef KEYHANDLER_H
# define KEYHANDLER_H

class KeyHandler
{
public:
	KeyHandler(void);
	~KeyHandler(void);

	void	readKeys(void);
	bool	isPressed(int keycode) const;
	void	reset(void);

private:
	KeyHandler(KeyHandler const& handler);

	KeyHandler& operator=(KeyHandler const& entity);

	static const int keyCount_ = 512;

	void	init(void);
	bool	keys_[keyCount_];
};

#endif

#include <string>

#include "Human.hpp"

int main(void)
{
	Human human;

	human.action("melee", "me");
	human.action("ranged", "me");
	human.action("shout", "me");
	human.action("do", "me");

	return (0);
}

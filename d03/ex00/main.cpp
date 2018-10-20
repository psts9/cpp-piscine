#include "FragTrap.hpp"

int	main(void)
{
	FragTrap fragTrap("CT-DUD3");

	fragTrap.rangedAttack("FR4G-TP");
	fragTrap.meleeAttack("FR4G-TP");
	fragTrap.takeDamage(15);
	fragTrap.takeDamage(999);
	fragTrap.beRepaired(45);
	fragTrap.beRepaired(999);
	fragTrap.vaulthunter_dot_exe("FR4G-TP");
	fragTrap.vaulthunter_dot_exe("FR4G-TP");
	fragTrap.vaulthunter_dot_exe("FR4G-TP");
	fragTrap.vaulthunter_dot_exe("FR4G-TP");
	fragTrap.vaulthunter_dot_exe("FR4G-TP");

	FragTrap dude = fragTrap;

	dude.rangedAttack("FR4G-TP");
	dude.meleeAttack("FR4G-TP");
	dude.takeDamage(15);
	dude.takeDamage(999);
	dude.beRepaired(45);
	dude.beRepaired(999);
	dude.vaulthunter_dot_exe("FR4G-TP");
	dude.vaulthunter_dot_exe("FR4G-TP");
	dude.vaulthunter_dot_exe("FR4G-TP");
	dude.vaulthunter_dot_exe("FR4G-TP");
	dude.vaulthunter_dot_exe("FR4G-TP");

	return (0);
}

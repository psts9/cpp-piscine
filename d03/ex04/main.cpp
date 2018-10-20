#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int	main(void)
{
	srand(time(NULL));

	ClapTrap clapTrap("CL4P-TP");

	std::cout << std::endl;

	FragTrap fragTrap("FR4G-TP");

	fragTrap.rangedAttack("SC4V-TP");
	fragTrap.meleeAttack("SC4V-TP");
	fragTrap.takeDamage(15);
	fragTrap.takeDamage(999);
	fragTrap.beRepaired(45);
	fragTrap.beRepaired(999);
	fragTrap.vaulthunter_dot_exe("SC4V-TP");
	fragTrap.vaulthunter_dot_exe("SC4V-TP");
	fragTrap.vaulthunter_dot_exe("SC4V-TP");
	fragTrap.vaulthunter_dot_exe("SC4V-TP");
	fragTrap.vaulthunter_dot_exe("SC4V-TP");

	std::cout << std::endl;

	ScavTrap scavTrap("SC4V-TP");

	scavTrap.rangedAttack("You");
	scavTrap.meleeAttack("You");
	scavTrap.takeDamage(15);
	scavTrap.takeDamage(999);
	scavTrap.beRepaired(45);
	scavTrap.beRepaired(999);
	scavTrap.challengeNewcomer("You");
	scavTrap.challengeNewcomer("You");
	scavTrap.challengeNewcomer("You");
	scavTrap.challengeNewcomer("You");
	scavTrap.challengeNewcomer("You");

	std::cout << std::endl;

	NinjaTrap ninjaTrap("N1NJ4-TP");

	ninjaTrap.rangedAttack("You");
	ninjaTrap.meleeAttack("You");
	ninjaTrap.takeDamage(15);
	ninjaTrap.takeDamage(999);
	ninjaTrap.beRepaired(45);
	ninjaTrap.beRepaired(999);
	ninjaTrap.ninjaShoebox(clapTrap);
	ninjaTrap.ninjaShoebox(fragTrap);
	ninjaTrap.ninjaShoebox(ninjaTrap);
	ninjaTrap.ninjaShoebox(scavTrap);

	std::cout << std::endl;

	SuperTrap superTrap("SUP3R-TP");

	std::cout << superTrap.getName() << std::endl;
	std::cout << superTrap.getLevel() << std::endl;
	std::cout << superTrap.getHitPoints() << std::endl;
	std::cout << superTrap.getEnergyPoints() << std::endl;
	std::cout << superTrap.getMaxHitPoints() << std::endl;
	std::cout << superTrap.getMaxEnergyPoints() << std::endl;
	std::cout << superTrap.getMeleeAttackDamage() << std::endl;
	std::cout << superTrap.getRangedAttackDamage() << std::endl;
	std::cout << superTrap.getArmorDamageReduction() << std::endl;
	superTrap.rangedAttack("me");
	superTrap.meleeAttack("you");
	superTrap.ninjaShoebox(scavTrap);
	superTrap.vaulthunter_dot_exe("SC4V-TP");


	return (0);
}

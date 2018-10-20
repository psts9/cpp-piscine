#include <iostream>

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main(void)
{
	PlasmaRifle rifle;

	std::cout << rifle.getName() << std::endl;
	std::cout << rifle.getAPCost() << std::endl;
	std::cout << rifle.getDamage() << std::endl;

	rifle.attack();

	std::cout << std::endl;

	PowerFist fist;

	std::cout << fist.getName() << std::endl;
	std::cout << fist.getAPCost() << std::endl;
	std::cout << fist.getDamage() << std::endl;

	fist.attack();

	std::cout << std::endl;

	SuperMutant mutant;

	std::cout << mutant.getType() << std::endl;
	std::cout << mutant.getHP() << std::endl;
	mutant.takeDamage(2);
	std::cout << mutant.getHP() << std::endl;
	mutant.takeDamage(6);
	std::cout << mutant.getHP() << std::endl;

	std::cout << std::endl;

	RadScorpion scorpion;

	std::cout << scorpion.getType() << std::endl;
	std::cout << scorpion.getHP() << std::endl;
	scorpion.takeDamage(2);
	std::cout << scorpion.getHP() << std::endl;
	scorpion.takeDamage(6);
	std::cout << scorpion.getHP() << std::endl;

	std::cout << std::endl;

//~--------------------------------------------------------~
	Character* zaz = new Character("zaz");

	std::cout << *zaz;

	Enemy *b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);

	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

	Enemy *m = new SuperMutant();

	zaz->attack(m);
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
	zaz->attack(m);
	std::cout << *zaz;
	zaz->attack(m);
//~--------------------------------------------------------~

	std::cout << std::endl;

	return (0);
}

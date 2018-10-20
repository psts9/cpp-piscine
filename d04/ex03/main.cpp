#include <iostream>

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* zaz = new Character("zaz");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);

	ICharacter* bob = new Character("bob");

	zaz->use(0, *bob);
	zaz->use(1, *bob);

	std::cout << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);
	tmp = src->createMateria("ice");
	zaz->equip(tmp);

	zaz->use(0, *bob);
	zaz->use(1, *bob);
	zaz->use(2, *bob);
	zaz->use(3, *bob);
	zaz->use(4, *bob);

	std::cout << std::endl;

	zaz->unequip(2);
	zaz->use(0, *bob);
	zaz->use(1, *bob);
	zaz->use(2, *bob);
	zaz->use(3, *bob);
	zaz->use(4, *bob);

	delete bob;
	delete zaz;
	delete src;

	return (0);
}

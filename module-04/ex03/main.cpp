#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  AMateria* ice = new Ice;
  AMateria* cure = new Cure;
  IMateriaSource *src = new MateriaSource();

  src->learnMateria(ice);
  src->learnMateria(cure);

  delete ice;
  delete cure;

  ICharacter *mark = new Character("mark");
  ICharacter *bob = new Character("bob");

  mark->equip(src->createMateria("ice"));
  mark->equip(src->createMateria("cure"));

  std::cout << "Name: " << mark->getName() << std::endl;
  std::cout << "Name: " << bob->getName() << std::endl;

  std::cout << "----------" << std::endl;

  mark->use(0, *bob);
  mark->use(1, *bob);
  mark->use(3, *bob);

  std::cout << "----------" << std::endl;
  
  *(static_cast<Character*>(mark)) = *(static_cast<Character*>(bob));

  std::cout << "Name: " << mark->getName() << std::endl;
  std::cout << "Name: " << bob->getName() << std::endl;

  std::cout << "----------" << std::endl;

  delete src;
  delete mark;
  delete bob;
}

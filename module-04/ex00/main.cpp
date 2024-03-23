#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
  const Animal* one = new Animal();
  const Animal* two = new Cat();
  const Animal* three = new Dog();

  std::cout << "-------------" << std::endl;

  one->makeSound();
  two->makeSound();
  three->makeSound();

  std::cout << "-------------" << std::endl;

  std::cout << "One type: " << one->getType() << std::endl;
  std::cout << "Two type: " << two->getType() << std::endl;
  std::cout << "Three type: " << three->getType() << std::endl;

  std::cout << "-------------" << std::endl;

  delete one;
  delete two;
  delete three;

  std::cout << "-------------" << std::endl;

  const WrongAnimal* wCat = new WrongCat();

  std::cout << "-------------" << std::endl;

  wCat->makeSound();

  std::cout << "-------------" << std::endl;

  delete wCat;

  return 0;
}


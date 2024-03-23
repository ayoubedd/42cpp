#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
  Dog(void);
  Dog(const Dog &source);
  ~Dog(void);

  Dog &operator=(const Dog &source);

  void makeSound(void) const;

private:
  Brain *_brain;
};

#endif // !__DOG_HPP__

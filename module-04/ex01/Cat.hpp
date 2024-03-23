#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
  Cat(void);
  Cat(const Cat &source);
  ~Cat(void);

  Cat &operator=(const Cat &source);

  void makeSound(void) const;

private:
  Brain *_brain;
};

#endif // !__CAT_HPP__

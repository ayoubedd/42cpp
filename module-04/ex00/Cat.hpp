#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal {
  public:
    Cat(void);
    Cat(const Cat& source);
    Cat& operator=(const Cat& source);
    ~Cat(void);

    void makeSound(void) const;
};

#endif // !__CAT_HPP__


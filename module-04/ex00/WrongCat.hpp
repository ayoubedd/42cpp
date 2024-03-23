#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat(void);
  WrongCat(const WrongCat &source);
  WrongCat &operator=(const WrongCat &source);
  ~WrongCat(void);

  void makeSound(void) const;
};

#endif // !__WRONGCAT_HPP__

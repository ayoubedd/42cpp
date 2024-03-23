#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <string>

class WrongAnimal {
public:
  WrongAnimal(void);
  WrongAnimal(const WrongAnimal &source);
  WrongAnimal &operator=(const WrongAnimal &source);
  ~WrongAnimal(void);

  void makeSound(void) const;
  const std::string &getType(void) const;

protected:
  std::string type;
};

#endif

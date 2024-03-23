#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>

class Animal {
public:
  Animal(void);
  Animal(const Animal &source);
  Animal &operator=(const Animal &source);
  virtual ~Animal(void);

  virtual void makeSound(void) const;
  const std::string &getType(void) const;

protected:
  std::string type;
};

#endif

#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include "Weapon.hpp"

class HumanA {
  public:
    HumanA(std::string name, Weapon& weapon);
    void attack(void) const;

  private:
    Weapon& weapon;
    std::string name;
};

#endif // !__HUMANA_HPP__

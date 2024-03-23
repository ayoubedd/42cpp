#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include "Weapon.hpp"
//
#include <string>

class HumanB {
  public:
    HumanB(std::string name);
    void attack(void) const;
    void setWeapon(Weapon& weapon);

  private:
    Weapon* weapon;
    std::string name;
};

#endif // !__HUMANB_HPP__

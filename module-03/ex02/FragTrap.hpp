#ifndef __FRAGTRAP_HPP__

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
  FragTrap(void);
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &src);
  ~FragTrap(void);

  FragTrap &operator=(const FragTrap &src);

  void highFivesGuys(void);

  static const int _hitPoints = 100;
  static const int _energy = 100;
  static const int _attackDamage = 30;
};

#endif // !__FRAGTRAP_HPP__

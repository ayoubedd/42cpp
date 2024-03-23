#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class Scavtrap : virtual public ClapTrap {
public:
  Scavtrap(void);
  Scavtrap(const std::string& name);
  Scavtrap(const Scavtrap& src);
  ~Scavtrap(void);

  Scavtrap& operator=(const Scavtrap& src);

  void guardGate(void);
  void attack(const std::string& target);

  static const int _hitPoints = 100;
  static const int _energy = 50;
  static const int _attackDamage = 20;
};

#endif // !__SCAVTRAP_HPP__

#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public Scavtrap, public FragTrap {
public:
  DiamondTrap(void);
  DiamondTrap(const DiamondTrap &src);
  DiamondTrap(const std::string &name);
  ~DiamondTrap(void);

  DiamondTrap &operator=(const DiamondTrap &src);

  void whoAmI(void) const;
  void attack(const std::string &target);

private:
  std::string name;
};

#endif // !__DIAMONDTRAP_HPP__

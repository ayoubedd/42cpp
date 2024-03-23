#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>

class ClapTrap {
public:
  ClapTrap(void);
  ClapTrap(const std::string &name);
  ClapTrap(const ClapTrap &source);
  ~ClapTrap(void);

  ClapTrap &operator=(const ClapTrap &source);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  const std::string &getName(void) const;
  int getHitPoints(void) const;
  int getEnergy(void) const;
  int getAttackDamage(void) const;

  static const int _hitPoints = 10;
  static const int _energy = 10;
  static const int _attackDamage = 0;

private:
  std::string name;
  int hitPoints;
  int energy;
  int attackDamage;
};

std::ostream &operator<<(std::ostream &stream, const ClapTrap &claptrap);

#endif // !__CLAPTRAP_HPP__

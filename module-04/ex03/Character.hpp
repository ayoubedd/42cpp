#ifndef __CHRACTER_HPP__
#define __CHRACTER_HPP__

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
  public:
    Character(void);
    Character(const std::string& name);
    Character(const Character& source);
    ~Character(void);

    Character& operator=(const Character& source);

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

  private:
    std::string _name;
    static const int _inventory_size = 4;
    AMateria* _inventory[_inventory_size];
};

#endif // !__CHRACTER_HPP__


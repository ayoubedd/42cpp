#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  public:
    MateriaSource(void);
    MateriaSource(const MateriaSource& source);
    ~MateriaSource(void);

    MateriaSource& operator=(const MateriaSource& source);
    
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);

  private:
    static const int _inventory_size = 4;
    AMateria* _inventory[_inventory_size];
};

#endif // !__MATERIASOURCE_HPP__

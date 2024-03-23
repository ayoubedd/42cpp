#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
  public:
    Ice(void);
    Ice(const Ice& source);
    ~Ice(void);
    
    Ice& operator=(const Ice& source);
    
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif


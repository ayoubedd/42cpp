#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
  public:
    Cure(void);
    Cure(const Cure& source);
    ~Cure(void);
    
    Cure& operator=(const Cure& source);
    
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif


#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <string>
class ICharacter;

class AMateria {
  public:
    AMateria(void);
    AMateria(const AMateria& source);
    AMateria(std::string const &type);
    virtual ~AMateria(void);

    AMateria& operator=(const AMateria& source);

    const std::string& getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);

  protected:
    std::string _type;
};

#endif


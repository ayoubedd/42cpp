#ifndef __ZOMBIE_HPP__

#include <string>

class Zombie {
  public:
    Zombie(void);
    ~Zombie();
    void announce(void);
    void setName(std::string name);

  private:
    std::string name;
};

Zombie* zombieHorde(int n, std::string name);

#endif // !__ZOMBIE_HPP__

#ifndef __ZOMBIE_HPP__

#include <string>

class Zombie {
  public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce(void);

  private:
    std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif // !__ZOMBIE_HPP__

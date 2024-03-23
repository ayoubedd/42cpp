#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <string>

class Brain {
  public:
    Brain(void);
    Brain(const Brain& source);
    ~Brain(void);

    Brain& operator=(const Brain& source);

  private:
    std::string ideas[100];
};


#endif // !__BRAIN_HPP__

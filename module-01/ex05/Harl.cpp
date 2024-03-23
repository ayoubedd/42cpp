#include "Harl.hpp"
#include <iostream>

void Harl::complain(std::string level) {
  typedef void (Harl::*HarlMemberFunc)(void);

  std::string keys[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  HarlMemberFunc funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
  for (std::size_t i = 0; i < keys->length(); i++) {
    if (level == keys[i])
      (*this.*funcs[i])();
  }
}

void Harl::debug(void) {
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
  std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

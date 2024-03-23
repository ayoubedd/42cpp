#include "Harl.hpp"
#include <iostream>

static void usage(void) {
  std::cout << "./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    usage();
    return 1;
  }

  Harl harl;

  harl.complain(argv[1]);
  return 0;
}

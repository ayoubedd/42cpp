#include "PmergeMe.hpp"
#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    std::cerr << "Error: invalid args" << std::endl;
    return EXIT_FAILURE;
  }

  std::clock_t then;
  double elapsed;

  then = std::clock();

  // Sorting using vector
  std::vector<int> sortedVec =
      sort<std::vector<std::pair<int, int> >, std::vector<int> >(argc - 1,
                                                               &argv[1]);

  elapsed = static_cast<double>(std::clock() - then) / CLOCKS_PER_SEC * 1000000;

  {
    std::cout << "Before: ";
    int i = 1;
    while (i < argc) {
      std::cout << argv[i] << " ";
      i++;
    }
    std::cout << std::endl;

    std::vector<int>::iterator resultBegin = sortedVec.begin();
    std::vector<int>::iterator resultEnd = sortedVec.end();

    std::cout << "After: ";
    while (resultBegin != resultEnd) {
      std::cout << *resultBegin << " ";
      resultBegin++;
    }
    std::cout << std::endl;
  }

  std::cout << "Time to process a range of " << argc - 1
            << " elements with std::vector : " << elapsed << " us" << std::endl;

  then = std::clock();

  // Sorting using deque
  sort<std::deque<std::pair<int, int> >, std::deque<int> >(argc - 1, &argv[1]);
  elapsed = static_cast<double>(std::clock() - then) / CLOCKS_PER_SEC * 1000000;

  std::cout << "Time to process a range of " << argc - 1
            << " elements with std::deque : " << elapsed << " us" << std::endl;
}

#include "Span.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

int main(void) {
  int i = 0;
  std::vector<int> vec(10000);

  std::srand(time(NULL));

  while (i < 10000) {
    vec[i] = std::rand() % 10001;
    i++;
  };

  try {
    Span span(10000);

    span.addRange(vec.begin(), vec.end());

    std::cout << "Longest span: " << span.longestSpan() << std::endl;
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
  } catch (const std::exception &ex) {
    std::cout << "Error: " << ex.what() << std::endl;
  }

  std::cout << "------------------------" << std::endl;

  vec.push_back(1337);

  try {
    Span span(10000);

    span.addRange(vec.begin(), vec.end());

    std::cout << "Longest span: " << span.longestSpan() << std::endl;
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;

  } catch (const std::exception &ex) {
    std::cout << "Error: " << ex.what() << std::endl;
  }

  std::cout << "------------------------" << std::endl;

  try {
    Span span = Span(1);

    span.addNumber(6);

    std::cout << span.longestSpan() << std::endl;
    std::cout << span.shortestSpan() << std::endl;

  } catch (const std::exception &ex) {
    std::cout << "Error: " << ex.what() << std::endl;
  }

  std::cout << "------------------------" << std::endl;

  try {
    Span span = Span(5);

    span.addNumber(6);
    span.addNumber(3);
    span.addNumber(17);
    span.addNumber(9);
    span.addNumber(11);

    std::cout << "Longest span: " << span.longestSpan() << std::endl;
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;

  } catch (const std::exception &ex) {
    std::cout << "Error: " << ex.what() << std::endl;
  }
}

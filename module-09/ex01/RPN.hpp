#pragma once

#include <stack>
#include <string>

class Rpn {
  std::stack<float> stack;

public:
  Rpn();
  Rpn(const Rpn &);
  Rpn &operator=(const Rpn &);
  ~Rpn();

  void repl(const std::string &);
  void printResult(void) const;
  size_t stackSize(void) const;
};

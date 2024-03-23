#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

Rpn::Rpn() {}

Rpn::Rpn(const Rpn &src) { *this = src; }

Rpn::~Rpn() {}

Rpn &Rpn::operator=(const Rpn &src) {
  stack = src.stack;
  return *this;
}

static std::string eatTillWhiteSpace(const std::string &content) {
  std::string::size_type i = 0;

  while (content[i] && isspace(content[i]) == 0)
    i++;

  return content.substr(0, i);
}

enum Token {
  NUMBER,
  ADDITION,
  MULTIPLICATION,
  DIVISION,
  SUBTRACTION,
  UNKNOWN,
};

static bool isNumber(const std::string &price) {
  std::string::size_type i = 0;
  bool passedFloatingPoint = false;
  bool passedSign = false;

  while (price[i]) {
    if (!isdigit(price[i])) {
      if (i != 0 && price[i] == '.' && passedFloatingPoint == false) {
        i++;
        passedFloatingPoint = true;
        continue;
      }
      if (i == 0 && (price[i] == '+' || price[i] == '-') &&
          passedSign == false) {
        passedSign = true;
        i++;
        continue;
      }
      return false;
    }
    i++;
  }

  if (price[price.length() - 1] == '.')
    return false;

  return true;
}

static bool isMathOp(const char c) {
  switch (c) {
  case '*':
  case '/':
  case '-':
  case '+':
    return true;

  default:
    return false;
  }
}

static Token whatMahtOp(const char c) {
  switch (c) {
  case '*':
    return MULTIPLICATION;
  case '/':
    return DIVISION;
  case '-':
    return SUBTRACTION;
  case '+':
    return ADDITION;

  default:
    return UNKNOWN;
  }
}

static Token getTokenType(const std::string &token) {
  if (token.empty())
    return UNKNOWN;
  if (token.length() == 1 && isMathOp(token[0]) == true)
    return whatMahtOp(token[0]);
  if (isNumber(token))
    return NUMBER;
  return UNKNOWN;
}

static float mathematicanOperation(Token op, float numOne, float numTwo) {
  switch (op) {
  case ADDITION:
    return numOne + numTwo;
  case MULTIPLICATION:
    return numOne * numTwo;
  case DIVISION: {
    if (numTwo == 0.0f)
      throw std::runtime_error("cannot divide by a zero");
    return numOne / numTwo;
  }
  case SUBTRACTION:
    return numOne - numTwo;
  case UNKNOWN:
  case NUMBER:
    return 0;
  }

  return 0;
}

std::string strTrim(const std::string &str) {
  std::string::size_type i = 0;
  std::string::size_type j = 0;

  std::string results;

  while (i < str.length()) {

    while (i < str.length() && isspace(str[i]))
      i++;

    j = i;
    while (j < str.length() && !isspace(str[j]))
      j++;

    if (i == j && i + j - i == str.length())
      break;

    results += (results.length() == 0 ? str.substr(i, j - i)
                                      : " " + str.substr(i, j - i));
    i += j - i;
  }

  return results;
}

void Rpn::repl(const std::string &expression) {
  std::string::size_type i = 0;
  std::string token;
  size_t performedOperations = 0;

  std::string input = strTrim(expression);
  if (input.empty())
    throw std::runtime_error("unexpected end of line");

  while (input[i]) {
    token = eatTillWhiteSpace(&input[i]);
    Token type = getTokenType(token);

    switch (type) {
    case NUMBER:
      stack.push(atof(token.c_str()));
      break;

    case UNKNOWN:
      throw std::runtime_error("unexpected token '" + token + "'");

    case ADDITION:
    case DIVISION:
    case SUBTRACTION:
    case MULTIPLICATION: {
      float numTwo;
      float numOne;

      if (stack.size() < 2)
        throw std::runtime_error(
            "no enough numbers in stack to perform operations");

      numTwo = stack.top();
      stack.pop();

      numOne = stack.top();
      stack.pop();

      stack.push(mathematicanOperation(type, numOne, numTwo));

      performedOperations++;
      break;
    }
    }

    i += token.length() + 1;

    if (i >= input.length())
      break;
  }

  if (performedOperations == 0)
    throw std::runtime_error("invalid polish notation");
}

void Rpn::printResult(void) const { std::cout << stack.top() << std::endl; }

size_t Rpn::stackSize(void) const { return stack.size(); }

#include "Fixed.hpp"
#include <iostream>

int main(void) {
  
  Fixed a(10);
  Fixed const b(Fixed(5.25f)*Fixed(2));

  std::cout << a << " > " << b << " \t: " << (a > b ? "true" : "false")  << std::endl;
  std::cout << a << " >= " << b << "\t: " << (a >= b ? "true" : "false")  << std::endl;
  std::cout << a << " < " << b << " \t: " << (a < b ? "true" : "false")  << std::endl;
  std::cout << a << " <= " << b << "\t: " << (a <= b ? "true" : "false")  << std::endl;
  std::cout << a << " == " << b << "\t: " << (a == b ? "true" : "false")  << std::endl;
  std::cout << a << " != " << b << "\t: " << (a != b ? "true" : "false")  << std::endl;

  std::cout << "--------------" << std::endl;

  std::cout << a << " + " << b << "\t= " << a + b << std::endl;
  std::cout << a << " - " << b << "\t= " << a - b << std::endl;
  std::cout << a << " * " << b << "\t= " << a * b << std::endl;
  std::cout << a << " / " << b << "\t= " << a / b << std::endl;

  std::cout << "--------------" << std::endl;

  std::cout << "a = " << a++ << ", a++ = " << a << std::endl;
  std::cout << "a = " << a-- << ", a-- = " << a << std::endl;

  std::cout << "--------------" << std::endl;

  std::cout << "a = " << a << ", b = " << b << "; Fixed::min(a,b) -> " << Fixed::min(a, b) << std::endl;
  std::cout << "a = " << a << ", b = " << b << "; Fixed::max(a,b) -> " << Fixed::max(a, b) << std::endl;

  return 0;
}

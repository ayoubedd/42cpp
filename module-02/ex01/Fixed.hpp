#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(const Fixed &source);
  Fixed(const int num);
  Fixed(const float num);
  Fixed &operator=(const Fixed &source);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int value;
  static const int fractionBits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &num);

#endif // !__FIXED_HPP__

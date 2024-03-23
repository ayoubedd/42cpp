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

  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  bool operator>(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  static Fixed& min(Fixed& one, Fixed& two);
  static const Fixed& min(const Fixed& one, const Fixed& two);

  static Fixed& max(Fixed& one, Fixed& two);
  static const Fixed& max(const Fixed& one, const Fixed& two);

private:
  int value;
  static const int fractionBits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &num);

#endif // !__FIXED_HPP__

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class Fixed {
  public:
    Fixed(void);
    Fixed(const Fixed& source);
    Fixed& operator=(const Fixed& source);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    int value;
    static const int fractionBits = 8;
};
#endif // !__FIXED_HPP__

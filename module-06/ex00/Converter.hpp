#ifndef __CONVERTER_HPP__
#define __CONVERTER_HPP__

#include <string>

class Converter {
  typedef enum {
    IPT_NON,
    IPT_CHAR,
    IPT_INT,
    IPT_FLOAT,
    IPT_DOUBLE,
    IPT_MINF,
    IPT_PINF,
    IPT_NAN
  } INPUT_TYPE;

public:
  Converter(void);
  Converter(const std::string &input);
  Converter(const Converter &src);
  ~Converter(void);

  Converter &operator=(const Converter &src);
  Converter &operator=(const std::string& src);

  void print(void) const;

private:
  std::string _input;
  INPUT_TYPE _inputType;

  char _charValue;
  int _intValue;
  float _floatValue;
  double _doubleValue;

  void initialize(void);
  void printChar(void) const;
  void printInt(void) const;
  void printFloat(void) const;
  void printDouble(void) const;

  bool isChar(void) const;
  bool isInt(void) const;
  bool isFloat(void) const;
  bool isDouble(void) const;

  void indentify(void);
  void convert(void);
};

std::ostream& operator<<(std::ostream& stream, const Converter& inst);

#endif // !__CONVERTER_HPP__


#include "Converter.hpp"
#include <string>
#include <iostream>
#include <iomanip>

void Converter::initialize(void) {
  _inputType = IPT_NON;
  _charValue = 0;
  _intValue = 0;
  _floatValue = 0;
  _doubleValue = 0;
}

Converter::Converter(void) {
  initialize();
}

Converter::Converter(const Converter& src) {
  *this = src;
}

Converter& Converter::operator=(const std::string& src) {
  _input = src;

  initialize();
  indentify();
  convert();

  return *this;
}

Converter& Converter::operator=(const Converter& src) {
  if (this == &src)
    return *this;

  _input = src._input;
  _inputType = src._inputType;
  _charValue = src._charValue;
  _intValue = src._intValue;
  _floatValue = src._floatValue;
  _doubleValue = src._doubleValue;

  return *this;
}

Converter::Converter(const std::string& input) : _input(input) {
  initialize();
  indentify();
  convert();
}

void Converter::indentify(void) {
  if (isInt())
    _inputType = IPT_INT;
  else if (isChar())
    _inputType = IPT_CHAR;
  else if (isFloat())
    _inputType = IPT_FLOAT;
  else if (isDouble())
    _inputType = IPT_DOUBLE;
  else if (_input == "+inff" || _input == "+inf")
    _inputType = IPT_PINF;
  else if (_input == "-inff" || _input == "-inf")
    _inputType = IPT_MINF;
  else if (_input == "nan" || _input == "nanf")
    _inputType = IPT_NAN;
}

void Converter::convert(void) {
  if (_inputType == IPT_CHAR)
    _charValue = _input[0];

  if (_inputType == IPT_INT)
    _intValue = std::stoi(_input);

  if (_inputType == IPT_FLOAT)
    _floatValue = std::stof(_input);

  if (_inputType == IPT_DOUBLE)
    _doubleValue = std::stod(_input);
}

void Converter::print(void) const {
  printChar();
  printInt();
  printFloat();
  printDouble();
}

void Converter::printChar(void) const {
  std::cout << "char: ";

  switch (_inputType) {
    case IPT_CHAR:
      std::cout << "'" << _charValue << "'" << std::endl;
      break;
    case IPT_INT:
      if (!(_intValue >= 32 && _intValue <= 126))
        std::cout << "Non displayable" << std::endl;
      else
        std::cout << "'" << static_cast<char>(_intValue) << "'" << std::endl;
      break;
    case IPT_FLOAT:
      if (!(_floatValue >= 32 && _floatValue <= 126))
        std::cout << "Non displayable" << std::endl;
      else
        std::cout << "'" << static_cast<char>(_floatValue) << "'" << std::endl;
      break;
    case IPT_DOUBLE:
      if (!(_doubleValue >= 32 && _doubleValue <= 126))
        std::cout << "Non displayable" << std::endl;
      else
        std::cout << "'" << static_cast<char>(_doubleValue) << "'" << std::endl;
      break;
    case IPT_PINF:
    case IPT_MINF:
    case IPT_NON:
    case IPT_NAN:
      std::cout << "impossible" << std::endl;
  }
}

void Converter::printInt(void) const {
  std::cout << "int: ";

  switch (_inputType) {
    case IPT_CHAR:
      std::cout << static_cast<int>(_charValue) << std::endl;
      break;
    case IPT_INT:
        std::cout << static_cast<int>(_intValue) << std::endl;
      break;
    case IPT_FLOAT:
        std::cout << static_cast<int>(_floatValue) << std::endl;
      break;
    case IPT_DOUBLE:
        std::cout << static_cast<int>(_doubleValue) << std::endl;
      break;
    case IPT_PINF:
    case IPT_MINF:
    case IPT_NON:
    case IPT_NAN:
      std::cout << "impossible" << std::endl;
  }
}


void Converter::printFloat(void) const {
  std::cout << "float: ";

  switch (_inputType) {
    case IPT_CHAR:
      std::cout << static_cast<float>(_charValue) << "f" << std::endl;
      break;
    case IPT_INT:
        std::cout << static_cast<float>(_intValue) << "f" << std::endl;
      break;
    case IPT_FLOAT:
        std::cout << static_cast<float>(_floatValue) << "f" << std::endl;
      break;
    case IPT_DOUBLE:
        std::cout << static_cast<float>(_doubleValue) << "f" << std::endl;
      break;
    case IPT_PINF:
      std::cout << "+inff" << std::endl;
      break;
    case IPT_MINF:
      std::cout << "-inff" << std::endl;
      break;
    case IPT_NAN:
      std::cout << "nanf" << std::endl;
      break;
    case IPT_NON:
      std::cout << "impossible" << std::endl;
  }
}

void Converter::printDouble(void) const {
  std::cout << "double: ";

  switch (_inputType) {
    case IPT_CHAR:
      std::cout << static_cast<double>(_charValue)<< std::endl;
      break;
    case IPT_INT:
        std::cout << static_cast<double>(_intValue)<< std::endl;
      break;
    case IPT_FLOAT:
        std::cout << static_cast<double>(_floatValue)<< std::endl;
      break;
    case IPT_DOUBLE:
        std::cout << static_cast<double>(_doubleValue)<< std::endl;
      break;
    case IPT_PINF:
      std::cout << "+inf" << std::endl;
      break;
    case IPT_MINF:
      std::cout << "-inf" << std::endl;
      break;
    case IPT_NAN:
      std::cout << "nan" << std::endl;
      break;
    case IPT_NON:
      std::cout << "impossible" << std::endl;
  }
}

Converter::~Converter(void) {

}

bool Converter::isInt(void) const {
  unsigned int i = 0;

  if (_input[0] == '+' || _input[0] == '-')
    i++;
  while (i < _input.length()) {
    if (!(_input[i] >= '0' && _input[i] <= '9'))
      return false;
    i++;
  }
  return true;
}

bool Converter::isChar(void) const {
  if (_input.length() == 1 && (_input[0] >= 32 && _input[0] <= 126))
    return true;
  return false;
}

bool Converter::isFloat(void) const {
  unsigned int i = 0;
  bool passedBinaryPoint = false;

  if (_input[0] == '+' || _input[0] == '-')
    i++;
  while (i < _input.length()) {
		if (_input[i] == '.') {
			if (!passedBinaryPoint) {
					passedBinaryPoint = true;
					i++;
					continue;
			} else
				return false;
			}
    if (!(_input[i] >= '0' && _input[i] <= '9')) {
      if (_input[i] == 'f' && i == (_input.length() - 1))
        return true;
      return false;
    }
    i++;
  }
  return false;
}

bool Converter::isDouble(void) const {
  unsigned int i = 0;
  bool passedBinaryPoint = false;

  if (_input[0] == '+' || _input[0] == '-')
    i++;
  while (i < _input.length()) {
		if (_input[i] == '.') {
			if (!passedBinaryPoint) {
					passedBinaryPoint = true;
					i++;
					continue;
			} else
				return false;
			}
    if (!(_input[i] >= '0' && _input[i] <= '9'))
      return false;
    i++;
  }
  return true;
}

std::ostream& operator<<(std::ostream& stream, const Converter& inst) {
  inst.print();
  return stream;
}


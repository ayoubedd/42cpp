#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
public:
  Array(void) {
    _size = 0;
    _array = NULL;
  }

  Array(const Array &src) {
    _size = src._size;
    _array = new T[_size];

    unsigned int i = 0;
    while (i < _size) {
      _array[i] = src._array[i];
      i++;
    }
  }

  Array(unsigned int init_size) {
    _size = init_size;
    _array = new T[init_size];

    unsigned int i = 0;
    while (i < init_size) {
      _array[i] = 0;
      i++;
    }
  }

  ~Array(void) {
    if (_array)
      delete[] _array;
  }

  unsigned int size(void) const { return _size; }

  Array &operator=(const Array &src) {
    _size = src._size;

    if (_array)
      delete[] _array;
    _array = new T[_size];

    unsigned int i = 0;
    while (i < _size) {
      _array[i] = src._array[i];
      i++;
    }

    return *this;
  }

  T &operator[](unsigned int idx) {
    if (idx >= _size)
      throw std::out_of_range("index out of range");

    return _array[idx];
  }

  const T &operator[](unsigned int idx) const {
    if (idx >= _size)
      throw std::out_of_range("index out of range");

    return _array[idx];
  }

private:
  unsigned int _size;
  T *_array;
};

#endif // !__ARRAY_HPP__


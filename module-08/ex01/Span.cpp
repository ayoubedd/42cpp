#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

Span::Span(void) {
  _array = NULL;
  _cap = 0;
  _elements = 0;
}

Span::Span(unsigned int size) {
  _cap = size;
  _array = new int[_cap];
  _elements = 0;
}

Span::Span(const Span &src) { *this = src; }

Span &Span::operator=(const Span &src) {
  if (this == &src)
    return *this;

  _cap = src._cap;
  _elements = src._elements;

  if (_array)
    delete[] _array;
  _array = new int[_cap];

  unsigned int i = 0;
  while (i < _elements) {
    _array[i] = src._array[i];
    i++;
  }

  return *this;
}

Span::~Span(void) {
  if (_array)
    delete[] _array;
}

void Span::addNumber(int num) {
  if (_elements >= _cap)
    throw Span::SpanFullException();

  _array[_elements] = num;
  _elements++;
}

int Span::shortestSpan(void) const {
  if (_elements <= 1)
    throw Span::SpanNotEnoughElementsException();

  int res;
  int tmp;
  unsigned int i = 0;
  unsigned int j;
  while (i + 1 < _elements) {
    j = i + 1;
    while (j < _elements) {
      tmp = _array[i] - _array[j];

      if (tmp < 0)
        tmp = ~tmp + 1;

      if (tmp < res || (!i && j == 1))
        res = tmp;
      j++;
    }
    i++;
  };

  return res;
}

int Span::longestSpan(void) const {
  if (_elements <= 1)
    throw Span::SpanNotEnoughElementsException();

	int* min = std::min_element(_array, _array + _elements);
	int* max = std::max_element(_array, _array + _elements);

  return *max - *min;
}


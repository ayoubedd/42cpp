#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <stdexcept>
#include <vector>

class Span {
public:
  Span(void);
  Span(unsigned int size);
  Span(const Span &src);
  ~Span(void);

  Span &operator=(const Span &src);

  void addNumber(int num);

  template <typename T>
	void addRange(T begin, T end) {
    while (begin != end) {
			addNumber(*begin);
      ++begin;
    }
  }

  int shortestSpan(void) const;
  int longestSpan(void) const;

  class SpanFullException : public std::exception {
  public:
    virtual const char *what() const throw() {
			return "Span capacity execeded";
		}
  };

  class SpanNotEnoughElementsException : public std::exception {
  public:
    virtual const char *what() const throw() {
			return "Span doesn't have enought element";
		}
  };

private:
  int *_array;
  unsigned int _elements;
  unsigned int _cap;
};

#endif // !__SPAN_HPP__


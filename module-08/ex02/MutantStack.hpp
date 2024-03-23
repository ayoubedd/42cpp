#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
public:
  typedef typename std::deque<T>::iterator iterator;
  typedef typename std::deque<T>::const_iterator const_iterator;

	MutantStack(void) {};

	MutantStack(const MutantStack& src) : std::stack<T>(src) {};

	~MutantStack(void) {};

	MutantStack& operator=(const MutantStack& src) {
		std::stack<T>::operator=(src);

		return *this;
	};

  iterator begin(void) {
		return std::begin(this->c);
	}

  iterator end(void) {
		return std::end(this->c);
  }

  const_iterator cbegin(void) {
		return std::begin(this->c);
	}

  const_iterator cend(void) {
		return std::end(this->c);
  }
};

#endif // !__MUTANTSTACK_HPP__

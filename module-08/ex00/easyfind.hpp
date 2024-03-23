#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <algorithm>
#include <stdexcept>

class EasyFindElementNotFoundExpt : public std::exception {
	public:
		virtual const char* what(void) const throw() {
			return "element not found";
		}
};

template<typename T>
typename T::iterator easyfind(T& container, int value) {
  typedef typename T::iterator Iter;

  Iter res = std::find(container.begin(), container.end(), value);
  if (res == container.end())
    throw EasyFindElementNotFoundExpt();
  return res;
}

template<typename T>
typename T::const_iterator easyfind(const T& container, int value) {
  typedef typename T::const_iterator Iter;

  Iter res = std::find(container.begin(), container.end(), value);
  if (res == container.end())
    throw EasyFindElementNotFoundExpt();
  return res;
}

#endif // !__EASYFIND_HPP__


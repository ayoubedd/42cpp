#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

template <typename T>
void swap(T& one, T& two) {
  T tmp = one;

  one = two;
  two = tmp;
}

template <typename T>
T& min(T& one, T& two) {
  if (one <= two)
    return one;
	return two;
}

template <typename T>
T& max(T& one, T& two) {
  if (two >= one)
    return two;
	return one;
}

#endif // !__WHATEVER_HPP__

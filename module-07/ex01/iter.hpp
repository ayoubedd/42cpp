#ifndef __ITER_HPP__
#define __ITER_HPP__

template<typename T>
void iter(T* array, unsigned int length, void (*func)(const T&)) {
  unsigned int i = 0;
  
  while (i < length) {
    func(array[i]);
    i++;
  }
}

#endif // !__ITER_HPP__


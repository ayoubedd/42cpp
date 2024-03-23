#include "Data.hpp"
#include <iostream>

uintptr_t serialize(Data* ptr) {
  uintptr_t ptrd = reinterpret_cast<uintptr_t>(ptr);
  return ptrd;
}

Data* deserialize(uintptr_t raw) {
  Data* ptr = reinterpret_cast<Data*>(raw);
  return ptr;
}

int main(void)
{
  Data* before = new Data;
  uintptr_t var = serialize(before);
  Data* after = deserialize(var);

  std::cout << "Befor: " << before << std::endl;
  std::cout << "After: " << after << std::endl;

  after->greeting();
}

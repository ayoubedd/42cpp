#include "Array.hpp"
#include <iostream>
#include <stdlib.h>

#define MAX_VAL 750

int main(void) {
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];

  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }

  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }

  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++)
    numbers[i] = rand();
  delete[] mirror;

  try {
    Array<int> nums;
    std::cout << nums[1] << std::endl;;
  } catch (const std::exception& ex) {
    std::cerr << ex.what() << std::endl;;
  }
	
	std::cout << "-------------------------" << std::endl;

	{
		Array<char> list(5);

		try {

			list[0] = 'A';
			list[1] = 'B';
			list[2] = 'C';
			list[3] = 'D';
			list[4] = 'E';

			std::cout << "list[0]: " << list[0] << std::endl;
			std::cout << "list[1]: " << list[1] << std::endl;
			std::cout << "list[2]: " << list[2] << std::endl;
			std::cout << "list[3]: " << list[3] << std::endl;
			std::cout << "list[4]: " << list[4] << std::endl;
			std::cout << "list[5]: " << list[5] << std::endl;

		} catch (const std::exception &ex) {
			std::cout << ex.what() << std::endl;
		}
	}
  return 0;
}

#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
  int i = 1;
  int j;

  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 0;
  }

  while (i < argc) {
    std::string str = argv[i];
    j = 0;
    while (str[j]){
      if (isalpha(str[j]))
        std::cout << (char)toupper(str[j]);
      else
        std::cout << str[j];
      j++;
    }
    i++;
  }
  std::cout << "\n";
  return 0;
}

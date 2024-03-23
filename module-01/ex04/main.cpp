#include <fstream>
#include <iostream>
#include <ios>
#include <string>

static std::ifstream::pos_type fileSize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

static void searchAndReplace(std::string& haystack, const std::string& niddle, const std::string& with) {
  std::size_t pos = 0;

  while (true) {
    pos = haystack.find(niddle, pos);
    if (pos == std::string::npos)
        break;
    haystack.erase(pos, niddle.length());
    haystack.insert(pos, with);
  }
}

static void printUsage(void) {
  std::cout << "./mysed <filename> <niddle> <replace>" << std::endl;
}

int main(int argc, char *argv[])
{
  if (argc != 4) {
      printUsage();
      return 1;
  }

  const std::string originalFileName = argv[1];
  const std::string newFileName = originalFileName + ".replace";
  std::ifstream originalFile;
  std::ofstream newFile;

  originalFile.open(originalFileName.c_str(), std::ios::in);
  newFile.open(newFileName.c_str(), std::ios::out);

  if (!originalFile.is_open() || !newFile.is_open()) {
    std::cerr << "Faild to open the files" << std::endl;
    return 1;
  }

  std::size_t size = fileSize(argv[1]);
  char* buffer = new char[size + 1];
  originalFile.read(buffer, size);
  buffer[size] = '\0';

  std::string fileContent = buffer;
  delete[] buffer;
  searchAndReplace(fileContent, argv[2], argv[3]);

  newFile << fileContent;

  newFile.close();
  originalFile.close();
}

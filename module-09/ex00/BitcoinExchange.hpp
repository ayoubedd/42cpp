#pragma once

#include <fstream>
#include <map>
#include <string>
#include <utility>

class BitcoinExchange {
  std::fstream dbFile;
  BitcoinExchange();

  std::map<size_t, double> prices;
  void parseDatabase(void);

public:
  typedef std::pair<std::string, std::string> dateValuePair;

  BitcoinExchange(const std::string &path);
  BitcoinExchange(const BitcoinExchange &);
  BitcoinExchange &operator=(const BitcoinExchange &);
  ~BitcoinExchange();

  double exchange(dateValuePair);
};

bool isValidInputHeader(const std::string &line);
bool isValidLine(const std::string &header, char sep, int numberOfColumns);
BitcoinExchange::dateValuePair parseLine(const std::string &line,
                                         const std::string &sep);

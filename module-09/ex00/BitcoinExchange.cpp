#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <string>
#include <utility>

struct ParsedDate {
  std::string year;
  std::string month;
  std::string day;
};

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
  this->prices = src.prices;
  return *this;
}

BitcoinExchange::BitcoinExchange(const std::string &path) {
  dbFile.open(path.c_str());

  if (dbFile.is_open() == false)
    throw std::runtime_error("failure opening database file");

  parseDatabase();
}

BitcoinExchange::~BitcoinExchange() { dbFile.close(); }

bool isValidLine(const std::string &header, char sep, int numberOfColumns) {
  std::string::size_type i = 0;
  int columns = 0;

  while (header[i]) {
    if (header[i] == sep)
      columns++;
    i++;
  }

  if (columns + 1 != numberOfColumns)
    return false;

  return true;
}
bool isValidInputHeader(const std::string &line) {
  BitcoinExchange::dateValuePair dateValuePair;

  if (isValidLine(line, '|', 2) == false)
    return false;

  try {
    dateValuePair = parseLine(line, "|");
    if (dateValuePair.first != "date" || dateValuePair.second != "value")
      return false;
  } catch (const std::exception &exp) {
    return false;
  }
  return true;
}

bool isValidDatabaseHeader(const std::string &line) {
  BitcoinExchange::dateValuePair dateValuePair;

  if (isValidLine(line, ',', 2) == false)
    return false;

  try {
    dateValuePair = parseLine(line, ",");
    if (dateValuePair.first != "date" ||
        dateValuePair.second != "exchange_rate")
      return false;
  } catch (const std::exception &exp) {
    return false;
  }

  return true;
}

std::string strTrim(const std::string &str) {
  std::string::size_type i = 0;
  std::string::size_type j = 0;

  while (str[i] && isspace(str[i]))
    i++;

  j = str.length() - 1;
  while (j > 0 && isspace(str[j]))
    j--;

  if (j - i + 1 <= 0)
    return "";

  return str.substr(i, j - i + 1);
}

BitcoinExchange::dateValuePair parseLine(const std::string &line,
                                         const std::string &sep) {
  BitcoinExchange::dateValuePair pair;
  std::string::size_type i;

  if (line.empty())
    throw std::runtime_error("empty line");

  i = line.find(sep);
  if (i == 0)
    throw std::runtime_error("missing date");

  if (i == std::string::npos)
    throw std::runtime_error("missing date, value separator");

  pair.first = line.substr(0, i);
  pair.first = strTrim(pair.first);

  if (pair.first.length() == 0)
    throw std::runtime_error("missing date in line");

  if (i + 1 >= line.length())
    throw std::runtime_error("missing value in line");

  pair.second = line.substr(i + 1);
  pair.second = strTrim(pair.second);

  return pair;
}

ParsedDate parseDateString(const std::string &dateStr) {
  ParsedDate date;

  std::string::size_type i = 0;
  std::string::size_type j = 0;
  while (dateStr[j] && isdigit(dateStr[j]))
    j++;

  if (dateStr[j] != '-' || (j == 0 && dateStr[j] == '-')) {
    if (j == dateStr.length())
      throw std::runtime_error("unexpected end of line.");
    else
      throw std::runtime_error("unexpected token '" +
                               (std::string() + dateStr[j]) + "'.");
  }
  date.year = dateStr.substr(i, j - i);

  j++;
  i = j;
  while (dateStr[j] && isdigit(dateStr[j]))
    j++;
  if (dateStr[j] != '-' || j == i) {
    if (j == dateStr.length())
      throw std::runtime_error("unexpected end of line.");
    else
      throw std::runtime_error("unexpected token '" +
                               (std::string() + dateStr[j]) + "'.");
  }
  date.month = dateStr.substr(i, j - i);

  j++;
  i = j;
  while (dateStr[j] && isdigit(dateStr[j]))
    j++;
  if (j != dateStr.length() || j == i) {
    if (j == dateStr.length())
      throw std::runtime_error("unexpected end of line.");
    else
      throw std::runtime_error("unexpected token '" +
                               (std::string() + dateStr[j]) + "'.");
  }
  date.day = dateStr.substr(i, j - i);

  return date;
}

static bool isYearLeap(size_t year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 100 == 0)
    return true;
  return false;
}

static size_t numberOfDaysInMonth(int month, bool isLeap) {
  int monthsDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  return (isLeap == true && month == 2 ? monthsDays[month - 1] + 1
                                       : monthsDays[month - 1]);
}

static size_t numberOfDaysInNYears(size_t years) {
  size_t i = 1;
  size_t days = 0;

  while (i <= years) {
    if (isYearLeap(i))
      days += 366;
    else
      days += 365;
    i++;
  }

  return days;
}

static size_t numberOfDaysInNMonths(size_t months, bool isLeap) {
  size_t i = 1;
  size_t days = 0;

  while (i <= months) {
    days += numberOfDaysInMonth(i, isLeap);
    i++;
  }

  return days;
}

ssize_t calcNumberOfDays(const ParsedDate &date) {
  size_t days = 0;
  size_t numberOfDaysIntheMonth;
  bool isLeap;

  size_t tmp;

  tmp = atoi(date.year.c_str());
  if (tmp <= 0)
    throw std::out_of_range("the year value is invalid");
  isLeap = isYearLeap(tmp);
  days = numberOfDaysInNYears(tmp);

  tmp = atoi(date.month.c_str());
  if (tmp > 12 || tmp < 1)
    throw std::out_of_range("month value is invalid => " + date.year + "-" +
                            date.month + "-" + date.day);

  numberOfDaysIntheMonth = numberOfDaysInMonth(tmp, isLeap);
  days += numberOfDaysInNMonths(tmp, isLeap);

  tmp = atoi(date.day.c_str());

  if (tmp > numberOfDaysIntheMonth)
    throw std::out_of_range("day of month is out of month days");
  days += tmp;

  return days;
}

static bool isValidPrice(const std::string &price) {
  std::string::size_type i = 0;
  bool passedFloatingPoint = false;
  bool passedSign = false;

  while (price[i]) {
    if (!isdigit(price[i])) {
      if (i != 0 && price[i] == '.' && passedFloatingPoint == false) {
        i++;
        passedFloatingPoint = true;
        continue;
      }
      if (i == 0 && (price[i] == '+' || price[i] == '-') &&
          passedSign == false) {
        passedSign = true;
        i++;
        continue;
      }
      return false;
    }
    i++;
  }

  if (price[price.length() - 1] == '.')
    return false;

  return true;
}

double BitcoinExchange::exchange(BitcoinExchange::dateValuePair pair) {
  ParsedDate date;
  size_t nDays;

  if (isValidPrice(pair.second) == false)
    throw std::runtime_error("input: invalid price value => " + pair.second);

  double factor = atof(pair.second.c_str());

  if (!(factor >= 0 && factor <= 1000))
    throw std::runtime_error("a valid value should be between 0 and 1000");

  date = parseDateString(pair.first);
  nDays = calcNumberOfDays(date);

  std::map<size_t, double>::iterator iter = prices.lower_bound(nDays);
  if (prices.empty())
    throw std::runtime_error("database is empty.");

  if (iter == prices.end())
    iter--;
  else if (iter->first > nDays && iter != prices.begin())
    iter--;

  if (iter->first > nDays)
    iter = prices.begin();

  return iter->second * factor;
}

void BitcoinExchange::parseDatabase() {
  BitcoinExchange::dateValuePair dateValuePair;
  bool preHeader = true;
  std::string line;
  ParsedDate date;

  while (true) {
    std::getline(dbFile, line);

    if (dbFile.eof())
      break;

    if (line.empty() == true)
      continue;

    if (preHeader == true && isValidDatabaseHeader(line) == false)
      throw std::runtime_error("database: invalid header => " + line);

    if (preHeader == true) {
      preHeader = false;
      continue;
    }

    if (isValidLine(line, ',', 2) == false)
      throw std::runtime_error("database: invalid line => " + line);

    try {
      dateValuePair = parseLine(line, ",");
      date = parseDateString(dateValuePair.first);
      size_t days = calcNumberOfDays(date);

      if (isValidPrice(dateValuePair.second) == false)
        throw std::runtime_error("invalid value in line => " + line);

      double price = atof(dateValuePair.second.c_str());
      prices.insert(std::pair<size_t, double>(days, price));

    } catch (const std::exception &exp) {
      throw std::runtime_error(std::string("database: ") + exp.what());
    }
  }
}

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
  this->_amount = initial_deposit;
  this->_accountIndex = Account::_nbAccounts;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex
    << ";amount:" << this->_amount
    << ";created" << std::endl;

  Account::_nbAccounts++;
  Account::_totalAmount += initial_deposit;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex
    << ";p_amount:" << this->_amount
    << ";deposit:" << deposit
    << ";amount:" << this->_amount + deposit
    << ";nb_deposits:" << this->_nbDeposits + 1
    << std::endl;

  this->_amount += deposit;
  this->_nbDeposits++;
  Account::_totalAmount += deposit;
  Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex
    << ";p_amount:" << this->_amount << ";withdrawal:";

  if (this->_amount < withdrawal) {
    std::cout << "refused" << std::endl;
    return false;
  }

  std::cout << withdrawal << ";amount:"
    << checkAmount() - withdrawal
    << ";nb_withdrawals:" << this->_nbWithdrawals + 1
    << std::endl;

  this->_amount -= withdrawal;
  this->_nbWithdrawals++;
  Account::_totalAmount -= withdrawal;
  Account::_totalNbWithdrawals++;
  return true;
}

int Account::checkAmount(void) const {
  return this->_amount;
}

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex
    << ";amount:" << checkAmount()
    << ";deposits:" << this->_nbDeposits
    << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::~Account(void) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex 
    << ";amount:" << checkAmount() 
    << ";closed" << std::endl;
}

// Static member functions
int Account::getNbAccounts(void) {
  return _nbAccounts;
}

int Account::getTotalAmount(void) {
  return _totalAmount;
}

int Account::getNbDeposits(void) {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() 
    << ";total:" << getTotalAmount() 
    << ";deposits:" << getNbDeposits() 
    << ";withdrawals:" << getNbWithdrawals() 
    << std::endl;
}

void Account::_displayTimestamp(void) {
  time_t now;

  std::time(&now);
  struct tm* elapsed = std::localtime(&now);
  std::cout << "["
    << elapsed->tm_year + 1900 << std::setfill('0') << std::setw(2)
    << elapsed->tm_mon + 1 << std::setfill('0') << std::setw(2)
    << elapsed->tm_mday
    << "_" << std::setfill('0') << std::setw(2)
    << elapsed->tm_hour << std::setfill('0') << std::setw(2)
    << elapsed->tm_min << std::setfill('0') << std::setw(2)
    << elapsed->tm_sec
    << "] ";
}


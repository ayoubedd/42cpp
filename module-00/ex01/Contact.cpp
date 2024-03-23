#include "Contact.hpp"

std::string Contact::getFirstName(void) const {
  return firstName;
}

std::string Contact::getLastName(void) const {
  return lastName;
}

std::string Contact::getNickName(void) const {
  return nickName;
}

std::string Contact::getPhoneNumber(void) const {
  return phoneNumber;
}

void Contact::setFirstName(std::string firstName) {
  this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
  this->lastName = lastName;
}

void Contact::setNickName(std::string nickName) {
  this->nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
  this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
  this->darkestSecret = darkestSecret;
}

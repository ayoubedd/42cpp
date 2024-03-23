#include <cstddef>
#ifndef __PHONEBOOK_HPP__

#include "Contact.hpp"

class PhoneBook {
  public:
    PhoneBook(void);
    void addContact(void);
    void searchContact(void) const;
    void printContactsTable(void) const;

  private:
    Contact contacts[8];
    int count;
};

#endif // !__PHONEBOOK_HPP__

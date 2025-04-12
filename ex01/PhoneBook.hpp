#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>
class PhoneBook {
private:
	Contact contacts[8];
	int contactCount;

public:
	PhoneBook();
	void addContact();
	void searchContacts() const;
};



#endif
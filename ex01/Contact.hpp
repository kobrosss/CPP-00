#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
	std::string firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string darkestSecret;

	public:
		Contact();
		void SetContact(std::string name, std::string surname, std::string nick,
			std::string phone, std::string secret);
		void ShowContacts() const;
		void ShowShort(int index) const;
};

#endif
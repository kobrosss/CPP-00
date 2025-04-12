#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0)
{
}

void PhoneBook::addContact()
{
	std::string first, last, nick, phone, secret;
	std::cout << "Enter First Name: ";
	std::getline(std::cin, first);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, last);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nick);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phone);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, secret);
	contacts[contactCount % 8].SetContact(first, last, nick, phone, secret);
	contactCount++;
	std::cout << "Contact added sucessfully!" << std::endl;
}

#include <limits> // Для std::numeric_limits

void PhoneBook::searchContacts() const
{
	std::cout << "| Index | First Name | Last Name | Nickname |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	int displayedContacts = (contactCount < 8 ? contactCount : 8);
	for (int i = 0; i < displayedContacts; i++)
		contacts[i].ShowShort(i);

	if (displayedContacts == 0)
	{
		std::cout << "No contacts available!" << std::endl;
		return ;
	}

	std::cout << "Enter index of contact to view: ";
	int index;

	if (!(std::cin >> index) || index < 0 || index >= displayedContacts)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index! Please enter a valid index." << std::endl;
		return ;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	contacts[index].ShowContacts();
}

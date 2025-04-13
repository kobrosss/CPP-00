/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:21:53 by rkobelie          #+#    #+#             */
/*   Updated: 2025/04/13 18:13:13 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>

bool	numberValidation(const std::string &phone)
{
	char	c;

	for (size_t i = 0; i < phone.length(); i++)
	{
		c = phone[i];
		if (!isdigit(c) && c != '+')
		{
			return (false);
		}
	}
	return (true);
}

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
	if (first.empty() || last.empty() || nick.empty() || phone.empty()
		|| secret.empty())
		std::cout << "Empty lines in contact!" << std::endl;
	else if(!numberValidation(phone))
		std::cout << "Invalid phone number! Only digits and '+' are allowed." << std::endl;
	else
	{
		contacts[contactCount % 8].SetContact(first, last, nick, phone, secret);
		contactCount++;
		std::cout << "Contact added sucessfully!" << std::endl;
	}
}

void PhoneBook::searchContacts() const
{
	std::cout << "|  Index  | First Name | Last Name |  Nickname  |" << std::endl;
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

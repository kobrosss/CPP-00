/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:21:39 by rkobelie          #+#    #+#             */
/*   Updated: 2025/04/13 17:55:35 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	darkestSecret = "";
}

void Contact::SetContact(std::string name, std::string surname,
	std::string nick, std::string phone, std::string secret)
{
	firstName = name;
	lastName = surname;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}

void Contact::ShowContacts() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::ShowShort(int index) const
{
	std::cout << "|" << std::setw(9) << index << "|  ";
	std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0,
			9) + "." : firstName) << "| ";
	std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0,
			9) + "." : lastName) << "|  ";
	std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0,
			9) + "." : nickname) << "|" << std::endl;
}

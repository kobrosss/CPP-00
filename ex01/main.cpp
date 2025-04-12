#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;

	std::string command;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEOF detected. Exiting..." << std::endl;
			break ;
		}
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}

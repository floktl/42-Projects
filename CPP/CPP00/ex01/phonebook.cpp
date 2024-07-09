/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:15:21 by flo               #+#    #+#             */
/*   Updated: 2024/07/07 15:10:03 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.Class.hpp"

int main()
{
	PhoneBook		phoneBook;
	std::string		command;
	std::string		name;

	while (command != "EXIT")
	{
		std::cout << "Type ADD to add  contact/ SEARCH to search a specific contact / EXIT to exit the programm\n";
		std::cin >> command;
		std::cout << std::endl;
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
		{
			if (phoneBook.get_size() != 0)
			{
				phoneBook.displayContacts();
				std::cout << "Type the contact you want to search for:" << std::endl;
				while (1)
				{
					std::string name;
					std::getline(std::cin >> std::ws, name);
					if (phoneBook.printContactByName(name) == 1)
						break ;
				}
			}
			else
				std::cout << "Phonebook empty!\n" << std::endl;
		}
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:15:21 by flo               #+#    #+#             */
/*   Updated: 2024/09/14 10:22:21 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

#include <iostream>
#include <csignal>

// Signal handler for SIGINT (Ctrl+C)
void signalHandler(int signum)
{
    std::cout << "\nInterrupt signal (" << signum
		<< ") received. Exiting program.\n";
    exit(signum);
}

int main()
{
	PhoneBook phoneBook;
    std::string command;
    std::string name;

    signal(SIGINT, signalHandler);
    while (true)
    {
        std::cout << "Type ADD to add a contact / SEARCH to search"
			<< " a specific contact / EXIT to exit the program\n";

        // Use std::getline to avoid stream issues with 'cin'
        if (!std::getline(std::cin >> std::ws, command))  // valid inputcheck
        {
            if (std::cin.eof())  // Catch EOF
            {
                std::cout << "\nEOF detected. Exiting program.\n";
                break;
            }
            else
            {
                std::cout << "Input error! Exiting program.\n";
                break;
            }
        }
        std::cout << std::endl;
        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            if (phoneBook.get_size() != 0)
            {
                phoneBook.displayContacts();
                std::cout << "Type the contact you want to search for:"
					<< std::endl;
                while (true)
                {
                    std::getline(std::cin >> std::ws, name);
					if (std::cin.eof())
						break ;
                    if (phoneBook.printContactByName(name) == 1)
                        break;
                }
            }
            else
            {
                std::cout << "Phonebook empty!\n" << std::endl;
            }
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting program.\n";
            break;
        }
        else
        {
            std::cout << "Unknown command! Please try again.\n";
        }
    }
    return (0);
}


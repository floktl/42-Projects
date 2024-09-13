/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:15:21 by flo               #+#    #+#             */
/*   Updated: 2024/09/11 16:08:53 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

#include <iostream>
#include <csignal>

PhoneBook phoneBook;

// Signal handler for SIGINT (Ctrl+C)
void signalHandler(int signum) {
    std::cout << "\nInterrupt signal (" << signum << ") received. Exiting program.\n";
    exit(signum);
}

int main()
{
    std::string command;
    std::string name;

    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, signalHandler);

    while (true) // Run until the program exits
    {
        std::cout << "Type ADD to add a contact / SEARCH to search"
			<< " a specific contact / EXIT to exit the program\n";

        // Use std::getline to avoid stream issues with 'cin'
        if (!std::getline(std::cin >> std::ws, command))  // Check if input is valid
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
                std::cout << "Type the contact you want to search for:" << std::endl;

                while (!std::cin.eof())
                {
                    std::getline(std::cin >> std::ws, name);
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

    return 0;
}


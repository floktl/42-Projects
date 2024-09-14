/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:15:21 by flo               #+#    #+#             */
/*   Updated: 2024/09/14 08:39:37 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"


// Definitions for PhoneBook class

PhoneBook::PhoneBook() : currentSize(0), size(0) {}

bool PhoneBook::isEmpty(const std::string &str) const
{
	return (str.empty());
}

// Function to check if the phone number is valid (outside the class)
bool isValidPhoneNumber(const std::string &number)
{
    // Allow only digits or a single '+' at the beginning
    if (number.empty())
		return (false);
    size_t start = 0;
    if (number[0] == '+')
        start = 1;
    for (size_t i = start; i < number.size(); ++i)
	{
        if (!std::isdigit(number[i]))
            return (false);
    }
    return (true);
}

void PhoneBook::promptForInput(const std::string& prompt, std::string &field) const
{
    std::cout << prompt;
    std::getline(std::cin >> std::ws, field); // std::ws removes leading whitesp.

	// Check for EOF after input
    if (std::cin.eof())
	{
        std::cout << "\nEOF detected. Exiting program.\n";
        exit(0);
    }
    while (isEmpty(field) || (prompt == "Phonenumber: "
		&& !isValidPhoneNumber(field)))
	{
        if (isEmpty(prompt))
		{
            std::cout << "No empty fields allowed. Please enter again: ";
        }
		else if (prompt == "Phonenumber: " && !isValidPhoneNumber(field))
		{
            std::cout << "Invalid phone number. Please enter a valid number: ";
        }
        std::getline(std::cin >> std::ws, field); // read input again, cut whitesp.
    }
}

std::string PhoneBook::truncateString(const std::string& str, size_t length) const
{
	if (str.length() > length)
		return (str.substr(0, length - 1) + ".");
	else
		return (str);
}

void PhoneBook::addContact()
{
	Contact new_contact;
	std::string first_name, last_name, nick_name, phone_number, darkest_secret;

	std::cout << "Write the contact information:\n" << std::endl;
	promptForInput("First name: ", first_name);
	promptForInput("Last name: ", last_name);
	promptForInput("Nick name: ", nick_name);
	promptForInput("Phonenumber: ", phone_number);
	promptForInput("Darkest secret: ", darkest_secret);

	new_contact.setFirstName(first_name);
	new_contact.setLastName(last_name);
	new_contact.setNickName(nick_name);
	new_contact.setPhoneNumber(phone_number);
	new_contact.setDarkestSecret(darkest_secret);

	contacts[currentSize++ % 8] = new_contact;
	if (currentSize <= 8)
		size++;
}

void PhoneBook::displayContacts() const
{
	std::cout << std::right << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;
	std::cout << std::right << "----------------------------------------"
		<< std::endl;

	for (int i = 0; i < currentSize && i < 8; ++i)
	{
		std::string first = truncateString(contacts[i].getFirstName(), 10);
		std::string last = truncateString(contacts[i].getLastName(), 10);
		std::string nick = truncateString(contacts[i].getNickName(), 10);

		std::cout << std::right << std::setw(10) << i + 1 << "|"
			<< std::setw(10) << first << "|"
			<< std::setw(10) << last << "|"
			<< std::setw(10) << nick << "\n" << std::endl;
	}
}

int PhoneBook::printContactByName(const std::string& name) const
{
	int index;

	for (size_t i = 0; i < name.size(); ++i)
	{
		if (!std::isdigit(name[i]))
		{
			std::cout << "Please choose a valid number, try again\n";
			return (0);
		}
	}
	index = std::stoi(name);
	if (index > size || index < 1)
	{
		std::cout << "Index out of Range, try again\n";
		return (0);
	}
	else
	{
		std::cout << "First name: " << contacts[index - 1].getFirstName()
			<< std::endl
			<< "Last name: " << contacts[index - 1].getLastName()
			<< std::endl
			<< "Nickname: " << contacts[index - 1].getNickName()
			<< std::endl
			<< "Phonenumber: " << contacts[index - 1].getPhoneNumber()
			<< std::endl
			<< "Darkest secret: " << contacts[index - 1].getDarkestSecret()
			<< "\n\n";
		return (1);
	}
}

int PhoneBook::get_size() const
{
	return (size);
}

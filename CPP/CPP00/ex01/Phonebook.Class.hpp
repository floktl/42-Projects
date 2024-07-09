/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:02:24 by flo               #+#    #+#             */
/*   Updated: 2024/07/09 15:24:04 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS
#define PHONEBOOK_CLASS

#include <iostream>
#include <iomanip>
#include <string>

//	the class for the contacts of the phonebook
class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phoneNumber;
		std::string darkest_secret;

	public:
		// Default constructor to initialize contact with default values
		Contact() {
			first_name = "Unknown";
			last_name = "Unknown";
			nick_name = "Unknown";
			phoneNumber = "Unknown";
			darkest_secret = "Unknown";
		}

		// Constructor to initialize contact with specific details
		Contact(const std::string& first_name, const std::string& last_name,
				const std::string& nick_name, const std::string& phoneNumber,
				const std::string& darkest_secret) {
			this->first_name = first_name;
			this->last_name = last_name;
			this->nick_name = nick_name;
			this->phoneNumber = phoneNumber;
			this->darkest_secret = darkest_secret;
		}
		// Getters to access contact information
		std::string getFirstName() const {
			return first_name;
		}
		std::string getLastName() const {
			return last_name;
		}
		std::string getNickName() const {
			return nick_name;
		}
		std::string getPhoneNumber() const {
			return phoneNumber;
		}
		std::string getDarkestSecret() const {
			return darkest_secret;
		}
		void setFirstName(const std::string& name) {
			first_name = name;
		}
		void setLastName(const std::string& name) {
			last_name = name;
		}
		void setNickName(const std::string& name) {
			nick_name = name;
		}
		void setPhoneNumber(const std::string& number) {
			phoneNumber = number;
		}
		void setDarkestSecret(const std::string& secret) {
			darkest_secret = secret;
		}
};

//	the class for the phonebook
class PhoneBook
{
	private:
		Contact contacts[8];
		int currentSize;
		int	size;

		//	function to check if a string is empty
		bool isEmpty(const std::string &str) const
		{
			return str.empty();
		}
		//	function to save input
		void promptForInput(const std::string& prompt, std::string &field) const
		{
			std::cout << prompt;
			std::getline(std::cin, field);
			while (isEmpty(field)) {
				std::getline(std::cin, field);
				if (isEmpty(field))
					std::cout << "No empty fields allowed. Please enter again: ";
			};
		}
		//	funciton to truncate a string with '.'
		std::string truncateString(const std::string& str, size_t length) const
		{
			if (str.length() > length)
				return str.substr(0, length - 1) + ".";
			else
				return str;
		}
	public:
		//	Constructor to initialize an empty phonebook
		PhoneBook()
		{
			currentSize = 0;
			size = 0;
		}
		//	function to add a new contact
		void addContact()
		{
			Contact new_contact;
			std::string first_name, last_name, nick_name, phone_number, darkest_secret;

			std::cout << "write the contact information:\n" << std::endl;
			// Prompt user for input and read values
			promptForInput("First name: ", first_name);
			promptForInput("Last name: ", last_name);
			promptForInput("Nick name: ", nick_name);
			promptForInput("Phonenumber: ", phone_number);
			promptForInput("darkest secret: ", darkest_secret);
			// Set values to the new_contact object
			new_contact.setFirstName(first_name);
			new_contact.setLastName(last_name);
			new_contact.setNickName(nick_name);
			new_contact.setPhoneNumber(phone_number);
			new_contact.setDarkestSecret(darkest_secret);
			// Updating the phonebooksize
			contacts[currentSize++ % 8] = new_contact;
			if (currentSize < 8)
				size++;
		}
		void displayContacts() const
		{
			//	first row, explainations
			std::cout << std::right << std::setw(10) << "Index" << "|"
					<< std::setw(10) << "First Name" << "|"
					<< std::setw(10) << "Last Name" << "|"
					<< std::setw(10) << "Nickname" << std::endl;
			std::cout << std::right << "----------------------------------------" << std::endl;
			//	loop for printing the first, last and nickname of the contacts
			for (int i = 0; i < currentSize; ++i)
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
		//	function to print full information of one contact
		int printContactByName(const std::string& name) const
		{
			int	index;

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
				std::cout << "First name: " << contacts[index - 1].getFirstName() << std::endl
					<< "Last name: " << contacts[index - 1].getLastName() << std::endl
					<< "Nickname: " << contacts[index - 1].getNickName() << std::endl
					<< "Phonenumber: " << contacts[index - 1].getPhoneNumber() << std::endl
					<< "Darkest secret: " << contacts[index - 1].getDarkestSecret() << "\n\n";
				return (1);
			}
			return (0);
		}
		int get_size() const
		{
			return size;
		}
};

#endif

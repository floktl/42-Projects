/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:02:24 by flo               #+#    #+#             */
/*   Updated: 2024/09/11 14:56:10 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

// The class for the phonebook
class PhoneBook
{
	private:
		Contact contacts[8];
		int currentSize;
		int size;

		bool isEmpty(const std::string &str) const;
		void promptForInput(const std::string& prompt, std::string &field) const;
		std::string truncateString(const std::string& str, size_t length) const;

	public:
		PhoneBook();

		void addContact();
		void displayContacts() const;
		int printContactByName(const std::string& name) const;
		int get_size() const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 07:51:52 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/11 16:25:23 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

// The class for the contacts of the phonebook
class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phoneNumber;
		std::string darkest_secret;

	public:
		Contact();
		Contact(const std::string& first_name, const std::string& last_name,
			const std::string& nick_name, const std::string& phoneNumber,
			const std::string& darkest_secret);

		// Getters
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		// Setters
		void setFirstName(const std::string& name);
		void setLastName(const std::string& name);
		void setNickName(const std::string& name);
		void setPhoneNumber(const std::string& number);
		void setDarkestSecret(const std::string& secret);
};

#endif // CONTACT_HPP

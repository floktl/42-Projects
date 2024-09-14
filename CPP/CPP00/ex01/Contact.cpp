/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:58:50 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/14 08:29:25 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Definitions for Contact class

Contact::Contact() {
	first_name = "Unknown";
	last_name = "Unknown";
	nick_name = "Unknown";
	phoneNumber = "Unknown";
	darkest_secret = "Unknown";
}

Contact::Contact(const std::string& first_name, const std::string& last_name,
                const std::string& nick_name, const std::string& phoneNumber,
                const std::string& darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phoneNumber = phoneNumber;
	this->darkest_secret = darkest_secret;
}

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickName() const { return nick_name; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkest_secret; }

void Contact::setFirstName(const std::string& name) { first_name = name; }
void Contact::setLastName(const std::string& name) { last_name = name; }
void Contact::setNickName(const std::string& name) { nick_name = name; }
void Contact::setPhoneNumber(const std::string& number) { phoneNumber = number; }
void Contact::setDarkestSecret(const std::string& secret) { darkest_secret = secret; }

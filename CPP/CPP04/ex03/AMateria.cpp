/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 07:10:10 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/03 07:23:22 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	type = "undefined";
	std::cout << "A nameless materia named " << type << " was created!"
		<< std::endl;
}

AMateria::AMateria(std::string const & type)
{
	AMateria::type = type;
	std::cout << "A materia named " << AMateria::type
		<< " was created!" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	AMateria::type = other.type;
	std::cout << "A materia named " << AMateria::type
		<< " was created!" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "AMateria named " << type << " copied" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria named " << AMateria::type
		<< " destroyed" << std::endl;
}

//	member functions

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter &  target)
{
	if (target.getName()  == "Ice")
	{

	}
}
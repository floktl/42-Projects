/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 07:10:10 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/04 08:00:53 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	type = "cure";
	std::cout << type << " was created!" << std::endl;
}

Cure::Cure(std::string const & type)
{
	Cure::type = type;
	std::cout << Cure::type << " was created!" << std::endl;
}

Cure::Cure(const Cure &other)  : AMateria(other)
{
	Cure::type = other.type;
	std::cout << Cure::type << " was created!" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << type << " copied" << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << Cure::type << " destroyed" << std::endl;
}

//	member functions

std::string const &Cure::getType() const
{
	return (this->type);
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}

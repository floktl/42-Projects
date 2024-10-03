/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 07:10:10 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/03 13:10:19 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	type = "ice";
	std::cout << type << " was created!" << std::endl;
}

Ice::Ice(std::string const & type)
{
	Ice::type = type;
	std::cout << Ice::type << " was created!" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	Ice::type = other.type;
	std::cout << Ice::type << " was created!" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout <<  type << " copied" << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << Ice::type << " destroyed" << std::endl;
}

//	member functions

std::string const &Ice::getType() const
{
	return (this->type);
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}

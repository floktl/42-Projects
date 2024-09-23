/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:25:37 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/21 15:17:48 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog() :Animal(), brain(new Brain())
{
	Dog::type = "Dog";
	std::cout << type << " has been created!" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) :Animal(other), brain(new Brain(*other.brain))
{
	std::cout << type << " copied!" << std::endl;
}

// copy assignment constructor
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

// Deconstructor
Dog::~Dog()
{
	delete brain;
	std::cout << "Dog has been brutally slaughtered!" << std::endl;
}

// member functions

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return brain;
}

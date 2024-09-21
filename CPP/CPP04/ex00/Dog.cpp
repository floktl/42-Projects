/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:25:37 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/20 13:14:22 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	Dog::type = "Dog";
	std::cout << "Dog has been created!" << std::endl;
}

Dog::~Dog()
{
	Dog::type = "Dog";
	std::cout << "Dog has been brutally slaughtered!" << std::endl;
}

Dog::Dog(const Dog &other)
{
	Dog::type = other.type;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
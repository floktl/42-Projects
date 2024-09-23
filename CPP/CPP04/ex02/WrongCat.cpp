/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:25:37 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/21 08:53:37 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	WrongCat::type = "WrongCat";
	std::cout << "WrongCat has been created!" << std::endl;
}

WrongCat::~WrongCat()
{
	WrongCat::type = "WrongCat";
	std::cout << "WrongCat has been brutally slaughtered!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)  :WrongAnimal(other)
{
	WrongCat::type = other.type;
}

void WrongCat::makeSound() const
{
	std::cout << "AHHH!" << std::endl;
}
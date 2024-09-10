/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:43:50 by flo               #+#    #+#             */
/*   Updated: 2024/07/16 10:37:30 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << HumanB::weapon->getType() << std::endl;
	else
		std::cout << name << " attacks with bare hands! " << std::endl;
}

void HumanB::setWeapon(Weapon &type)
{
	HumanB::weapon = &type;
}

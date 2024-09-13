/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:43:50 by flo               #+#    #+#             */
/*   Updated: 2024/09/12 08:28:25 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their "
			<< HumanB::weapon->getType() << std::endl;
	else
		std::cout << name << " attacks with bare hands! " << std::endl;
}

void HumanB::setWeapon(Weapon &type)
{
	HumanB::weapon = &type;
}

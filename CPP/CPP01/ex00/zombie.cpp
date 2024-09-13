/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:59:27 by flo               #+#    #+#             */
/*   Updated: 2024/09/12 07:39:21 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

int main(void)
{
	Zombie zombie_1("Foo");
	zombie_1.announce();

	Zombie *zombie_2 = newZombie("Zoo");
	zombie_2->announce();

	randomChump("name");
	delete zombie_2;
}

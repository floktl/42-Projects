/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:59:27 by flo               #+#    #+#             */
/*   Updated: 2024/07/09 13:50:44 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.Class.hpp"

int main(void)
{
	Zombie zombie_1("Foo");
	zombie_1.announce();

	Zombie *zombie_2 = newZombie("Zoo");
	zombie_2->announce();

	randomChump("name");
	delete zombie_2;
}

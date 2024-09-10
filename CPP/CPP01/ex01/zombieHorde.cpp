/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:15:05 by flo               #+#    #+#             */
/*   Updated: 2024/07/15 10:35:35 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.Class.hpp"

// Function to set the name
void Zombie::setName(std::string name)
{
	this->name = name;
	std::cout << name << " named" << std::endl;
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombies;

	zombies = new Zombie[N];
	if (N <= 0)
		return NULL;
	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}
	return (zombies);
}

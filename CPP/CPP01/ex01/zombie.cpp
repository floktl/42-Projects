/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:31:32 by flo               #+#    #+#             */
/*   Updated: 2024/09/12 08:14:52 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

int main(void)
{
	Zombie *zombies;
	int N = 5;

	zombies = zombieHorde(N, "Hello");
	if (zombies != NULL)
	{
		for (int i = 0; i < N; ++i)
		{
			zombies[i].announce();
		}
		delete[] zombies;
	}
	else
		std::cout << "No zombies allocated!";
}

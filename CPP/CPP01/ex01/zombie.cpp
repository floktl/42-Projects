/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:31:32 by flo               #+#    #+#             */
/*   Updated: 2024/07/09 15:28:28 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.Class.hpp"

int main(void)
{
	Zombie *zombies;
	int N = 5;

	zombies = zombieHorde(N, "Hello");
	if (zombies)
	{
		//zombies[0].announce();
		delete[] zombies;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:31:32 by flo               #+#    #+#             */
/*   Updated: 2024/07/15 10:53:41 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.Class.hpp"

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

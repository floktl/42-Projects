/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:56:52 by flo               #+#    #+#             */
/*   Updated: 2024/07/15 10:49:22 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
	#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	// Default constructor
	Zombie() : name("Unnamed")
	{
		std::cout << name << " initialized" << std::endl;
	}

	// Parameterized constructor
	Zombie(std::string name) : name(name)
	{
		std::cout << name << " initialized" << std::endl;
	}
	// Destructor
	~Zombie()
	{
		std::cout << name << " deconstructed" << std::endl;
	}
	void announce( void )
	{
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}
	// Function to set the name
	void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP

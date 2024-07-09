/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:07:23 by flo               #+#    #+#             */
/*   Updated: 2024/07/09 13:50:30 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef ZOMBIE
#define ZOMBIE_HPP

class Zombie
{
	private:
		std::string	name;
	public:

	Zombie(std::string name) :name(name) {};
	void announce( void )
	{
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}
	~Zombie()
	{
		std::cout << name << " deconstructed!" << std::endl;
	};
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif

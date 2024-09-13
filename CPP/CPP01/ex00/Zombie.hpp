/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:07:23 by flo               #+#    #+#             */
/*   Updated: 2024/09/12 07:40:26 by fkeitel          ###   ########.fr       */
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
	void announce( void );
	~Zombie() { std::cout << name << " deconstructed!" << std::endl; };
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif

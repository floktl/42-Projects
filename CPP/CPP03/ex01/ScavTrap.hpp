/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:13:54 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/17 10:26:06 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SVACTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
//class Claptrap;

class ScavTrap : public ClapTrap
{
private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
	// Default constructor
	ScavTrap();
	ScavTrap(const std::string& name);
	// Copy constructor
	ScavTrap(const ScavTrap& other);
	// Copy assignment operator
	ScavTrap& operator=(const ScavTrap& other);
	// Destructor
    ~ScavTrap();

	// member functions
	void guardGate();
	//void  beRepaired(unsigned int amount);
	//void takeDamage(unsigned int amount);
	//void attack(const std::string& target);
};

#endif

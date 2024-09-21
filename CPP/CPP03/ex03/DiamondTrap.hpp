/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:13:54 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/19 13:50:25 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :  public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	// Default constructor
	DiamondTrap();
	//	constructor
	DiamondTrap(const std::string& name);
	// Copy constructor
	DiamondTrap(const DiamondTrap& other);
	// Copy assignment operator
	DiamondTrap& operator=(const DiamondTrap& other);
	// Destructor
    ~DiamondTrap();

	// member functions
	void whoAmI();
};

#endif

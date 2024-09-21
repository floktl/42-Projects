/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:13:54 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/19 10:50:42 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool guarded;
public:
	// Default constructor
	ScavTrap();
	//	constructor
	ScavTrap(const std::string& name);
	// Copy constructor
	ScavTrap(const ScavTrap& other);
	// Copy assignment operator
	ScavTrap& operator=(const ScavTrap& other);
	// Destructor
    ~ScavTrap();

	// member functions
	void guardGate();
};

#endif

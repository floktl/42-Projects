/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:13:54 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/20 10:38:50 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	bool guarded;
public:
	// Default constructor
	FragTrap();
	//	constructor
	FragTrap(const std::string& name);
	// Copy constructor
	FragTrap(const FragTrap& other);
	// Copy assignment operator
	FragTrap& operator=(const FragTrap& other);
	// Destructor
    ~FragTrap();

	// member functions
	void highFivesGuys(void);
	static const unsigned int default_hitPoints = 100;
	static const unsigned int default_energypoints = 100;
	static const unsigned int default_attackDamage = 30;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:12:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/20 10:48:32 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("uninitialized_clap_name"),	// Initialize ClapTrap with name
	ScavTrap("uninitialized_clap_name"),	// Default constructor for ScavTrap
	FragTrap("uninitialized_clap_name"),	// Default constructor for FragTrap
	name("uninitialized_diamond_name")		// DiamondTrap-specific name
{
	setHit(FragTrap::default_hitPoints);	// Set the hit points
	setEng(ScavTrap::default_energypoints);	// Set the energy points
	setAtt(FragTrap::default_attackDamage);	// Set the attack damage
	std::cout << "DiamondTrap " << DiamondTrap::name
		<< " has been created!" << std::endl;
}


// constuctor
DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"),
	name(name + "_diamond_name")
{
	setHit(FragTrap::default_hitPoints);	// Set the hit points
	setEng(ScavTrap::default_energypoints);	// Set the energy points
	setAtt(FragTrap::default_attackDamage);	// Set the attack damage
	std::cout << "DiamondTrap " << DiamondTrap::name
		<< " has been created!" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other),	// Call ClapTrap copy constructor via inheritance chain
      ScavTrap(other),	// Call ScavTrap copy constructor
      FragTrap(other),	// Call FragTrap copy constructor
      name(other.name)	// Copy DiamondTrap-specific name
{
    this->setHit(other.hitPoints);		// Copy the hit points
    this->setEng(other.energyPoints);	// Copy the energy points
    this->setAtt(other.attackDamage);	// Copy the attack damage
    std::cout << "DiamondTrap " << DiamondTrap::name
		<< " has been created!" << std::endl;
}



//	copy assignment conctructor
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

// destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " has been destroyed!"
	<< std::endl;
}

//	guard funciton
void DiamondTrap::whoAmI()
{
	std::cout << "Hello i am " << this->name << " my grandfather is "
		<< ClapTrap::name << std::endl;
}

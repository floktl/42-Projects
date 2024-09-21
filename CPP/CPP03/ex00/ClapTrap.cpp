/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:35:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/20 08:54:11 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

// default Constructor
ClapTrap::ClapTrap()
	: name("uninitialized"), hitPoints(0), energyPoints(0), attackDamage(0)
{
	std::cout << "default Constructor called" << std::endl;
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name),
	hitPoints(other.hitPoints), energyPoints(other.energyPoints),
	attackDamage(other.attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

//--------------------------- member functions ------------------------

// Attack function
void ClapTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target
			<< ", causing " << attackDamage << " points of damage!"
			<< std::endl;
		energyPoints--;
	}
	else
		std::cout << "ClapTrap " << name
			<< " can't attack due to lack of hit points or energy points."
			<< std::endl;
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0) {
		hitPoints -= amount;
		if (hitPoints < 0) hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes "
			<< amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is already down!"
			<< std::endl;
}

// Repair function
void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " repairs itself, gaining "
			<< amount << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name
			<< " can't repair due to lack of hit points or energy points."
			<< std::endl;
}

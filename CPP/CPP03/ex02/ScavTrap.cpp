/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:12:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/19 11:00:49 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//	default constructor
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap uninitialized has been created!" << std::endl;
}

// constuctor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->setHit(100);
	this->setEng(50);
	this->setAtt(20);
	this->guarded = false;
	std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other)
{
	ClapTrap::name = other.name;
	this->setHit(other.hitPoints);
	this->setEng(other.energyPoints);
	this->setAtt(other.attackDamage);
	this->guarded = false;
}

//	copy assignment conctructor
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
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
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " has been destroyed!"
	<< std::endl;
}

//	guard funciton
void ScavTrap::guardGate()
{
	if (this->getHit() == 0)
	{
		std::cout << "Can't guard: " << this->getName()
			<< " has no healthpoints left!" << std::endl;
	}
	if (guarded != true)
	{
	guarded = true;
	std::cout << "Activating Gate-Keeper Modus for "
		<< this->getName() << "!" << std::endl;
	}
}

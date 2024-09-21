/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:35:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/20 09:03:04 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(100), energyPoints(50), attackDamage(20)
{
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

// default Constructor
ClapTrap::ClapTrap()
	: name("uninitialized"), hitPoints(0), energyPoints(0), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name),
	hitPoints(other.hitPoints), energyPoints(other.energyPoints),
	attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
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
	std::cout << "ClapTrap " << this->name << " has been destroyed!"
		<< std::endl;
}

//----------------------- getter/setter functions -----------------------

//	getters

std::string ClapTrap::getName()
{
	return (name);
}

int ClapTrap::getHit()
{
	return (hitPoints);
}

int ClapTrap::getEng()
{
	return (energyPoints);
}

int ClapTrap::getAtt()
{
	return (attackDamage);
}

//	setters

void ClapTrap::setHit(int value)
{
	//std::cout << "setting hp from " << this->getName() << " to "
	//	<< value << std::endl;
	hitPoints = value;
}

void ClapTrap::setEng(int value)
{
	//std::cout << "setting ep from " << this->getName() << " to "
	//	<< energyPoints << std::endl;
	energyPoints = value;
}

void ClapTrap::setAtt(int value)
{
	//std::cout << "setting att from " << this->getName() << " to "
	//	<< value << std::endl;
	attackDamage = value;
}

//--------------------------- member functions ------------------------

// Attack function
void ClapTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target
			<< ", causing " << attackDamage << " points of damage!"
			<< std::endl;
		energyPoints--;
		std::cout << name << " has " << energyPoints << " energy left"
			<< std::endl;
	}
	else
		std::cout << "ClapTrap " << name
			<< " can't attack due to lack of hit points or energy points."
			<< std::endl;
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
	{
		hitPoints -= amount;
		if (hitPoints < 0) hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes "
			<< amount << " points of damage!" << std::endl;
		std::cout << name << " has " << hitPoints << " hitPoints left"
			<< std::endl;
	}
	else
		std::cout << "ClapTrap " << name
			<< " can't take damage, is already down!" << std::endl;
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
		std::cout << name << " has " << energyPoints << " energy left"
			<< std::endl;
	}
	else
		std::cout << "ClapTrap " << name
			<< " can't repair due to lack of hit points or energy points."
			<< std::endl;
}

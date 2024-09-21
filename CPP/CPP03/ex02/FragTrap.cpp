/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:12:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/19 11:21:49 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//	default constructor
FragTrap::FragTrap()
{
	std::cout << "FragTrap uninitialized has been created!" << std::endl;
}

// constuctor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->setHit(100);
	this->setEng(50);
	this->setAtt(20);
	this->guarded = false;
	std::cout << "FragTrap " << name << " has been created!" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other)
{
	ClapTrap::name = other.name;
	this->setHit(other.hitPoints);
	this->setEng(other.energyPoints);
	this->setAtt(other.attackDamage);
	this->guarded = false;
}

//	copy assignment conctructor
FragTrap& FragTrap::operator=(const FragTrap& other)
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
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " has been destroyed!"
	<< std::endl;
}

//	guard funciton
void FragTrap::highFivesGuys(void)
{
	if (this->getHit() == 0)
	{
		std::cout << "Can't highFive: " << this->getName()
			<< " has no healthpoints left!" << std::endl;
	}
	if (guarded != true)
	{
	guarded = true;
	std::cout << "high Five guys from "
		<< this->getName() << " !!!" << std::endl;
	}
}

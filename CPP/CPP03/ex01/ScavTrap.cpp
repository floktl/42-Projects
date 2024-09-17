/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:12:29 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/17 10:22:52 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : hitPoints(100), attackDamage(20), energyPoints(50) {}

ScavTrap::ScavTrap(const std::string& name) : name(name), hitPoints(100), attackDamage(20), energyPoints(50) {}

ScavTrap::ScavTrap(const ScavTrap& other) : name(other.name),hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {}


void ScavTrap::guardGate() {
	std::cout << "Activating Gate-Keeper Modus: YOU SHALL NOT PASS!" << std::endl;
}

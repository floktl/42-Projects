/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:19:46 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/19 10:56:43 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
	// Default constructor
	ClapTrap();
	ClapTrap(const std::string& name);
	// Copy constructor
	ClapTrap(const ClapTrap& other);
	// Copy assignment operator
	ClapTrap& operator=(const ClapTrap& other);
	// Destructor
    ~ClapTrap();

	// member functions
	void  beRepaired(unsigned int amount);
	void takeDamage(unsigned int amount);
	void attack(const std::string& target);

	// getter functions
	std::string getName();
	int	getHit();
	int getEng();
	int	getAtt();
	// setter functions
	void setHit(int value);
	void setEng(int value);
	void setAtt(int value);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:30:48 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/19 11:21:22 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap claptrap("Freddy");
    std::cout << "name: " << claptrap.getName() << std::endl;
    std::cout << "hp: " << claptrap.getHit() << std::endl;
    std::cout << "ep: " << claptrap.getEng() << std::endl;
    std::cout << "attDmg: " << claptrap.getAtt() << std::endl;
    ScavTrap claptrap2(claptrap);
    FragTrap claptrap3;
    std::cout << "default name: " << claptrap3.getName() << std::endl;
    std::cout << "default hp: " << claptrap.getHit() << std::endl;
    std::cout << "default ep: " << claptrap.getEng() << std::endl;
    std::cout << "default attDmg: " << claptrap.getAtt() << std::endl;
    FragTrap claptrap4("Springtrap");
    claptrap3 = claptrap4;

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    for (int i = 0; i < 5; i++)
	{
        std::cout << "attack " << i << " -----" << std::endl;
        claptrap.attack("Springtrap");
        claptrap4.takeDamage(claptrap.getAtt());
        std::cout << std::endl;
    }

    std::cout << "edge cases -----" << std::endl;
    claptrap.attack("Springtrap");
    claptrap4.attack("Freddy");

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    claptrap.beRepaired(5);
    claptrap4.beRepaired(5);

    claptrap2.beRepaired(5);
    claptrap3.beRepaired(5);

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    claptrap2.attack("Springtrap");
    claptrap4.takeDamage(claptrap2.getAtt());

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    claptrap3.highFivesGuys();
    claptrap3.setHit(0);
    claptrap3.highFivesGuys();

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    return (0);
}
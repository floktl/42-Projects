/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:30:48 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/20 10:54:37 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamondtrap("Freddy");
    std::cout << "name: " << diamondtrap.getName() << std::endl;
    std::cout << "hp: " << diamondtrap.getHit() << std::endl;
    std::cout << "ep: " << diamondtrap.getEng() << std::endl;
    std::cout << "attDmg: " << diamondtrap.getAtt() << std::endl;
    DiamondTrap diamondtrap2(diamondtrap);
    DiamondTrap diamondtrap3;
    std::cout << "default name: " << diamondtrap3.getName() << std::endl;
    std::cout << "default hp: " << diamondtrap.getHit() << std::endl;
    std::cout << "default ep: " << diamondtrap.getEng() << std::endl;
    std::cout << "default attDmg: " << diamondtrap.getAtt() << std::endl;
    DiamondTrap diamondtrap4("Springtrap");
    diamondtrap3 = diamondtrap4;

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    for (int i = 0; i < 6; i++)
	{
        std::cout << "attack " << i << " -----" << std::endl;
        diamondtrap.attack("Springtrap");
        diamondtrap4.takeDamage(diamondtrap.getAtt());
        std::cout << std::endl;
    }

    std::cout << "edge cases -----" << std::endl;
    diamondtrap.attack("Springtrap");
    diamondtrap4.attack("Freddy");

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    diamondtrap.beRepaired(5);
    diamondtrap4.beRepaired(5);

    diamondtrap2.beRepaired(5);
    diamondtrap3.beRepaired(5);

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    diamondtrap2.attack("Springtrap");
    diamondtrap4.takeDamage(diamondtrap2.getAtt());

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    diamondtrap2.highFivesGuys();
    diamondtrap2.setHit(0);
    diamondtrap2.highFivesGuys();

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    diamondtrap.guardGate();
    diamondtrap2.setHit(0);
    diamondtrap.guardGate();

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    diamondtrap.whoAmI();
	diamondtrap2.whoAmI();
	diamondtrap3.whoAmI();
	diamondtrap4.whoAmI();

    std::cout << std::endl << "--------------------------------"
		<< std::endl << std::endl;

    return (0);
}

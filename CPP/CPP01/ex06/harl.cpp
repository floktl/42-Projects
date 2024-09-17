/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:21 by flo               #+#    #+#             */
/*   Updated: 2024/09/15 08:50:16 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
		<< "pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I can't believe adding extra bacon costs more money. You didn't put"
		<< "enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for "
		<< "years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    int level_index = -1;

    // Find the index of the level string
    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            level_index = i;
            break;
        }
    }
    // Implement the switch-case logic using the index
	switch (level_index) {
			case 0:
				std::cout << "[ " << levels[0] << " ]" << std::endl;
				(this->*functions[0])();
				// Fall through
			case 1:
				std::cout << "[ " << levels[1] << " ]" << std::endl;
				(this->*functions[1])();
				// Fall through
			case 2:
				std::cout << "[ " << levels[2] << " ]" << std::endl;
				(this->*functions[2])();
				// Fall through
			case 3:
				std::cout << "[ " << levels[3] << " ]" << std::endl;
				(this->*functions[3])();
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				break;
		}
}


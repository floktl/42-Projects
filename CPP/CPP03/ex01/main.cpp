/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:30:48 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/16 14:16:35 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("CL4P-TP");
    ClapTrap clap1;

	clap1.attack("hello");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    return 0;
}
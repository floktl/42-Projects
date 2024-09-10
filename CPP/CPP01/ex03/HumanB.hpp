/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:19:58 by flo               #+#    #+#             */
/*   Updated: 2024/07/16 10:36:04 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB
	#define HUMANB

#include "Weapon.hpp"
#include "string"
#include "iostream"

class HumanB
{
private:
	std::string name;
	Weapon *weapon;
public:
	HumanB(std::string name) :name(name), weapon(NULL) {};
	void setWeapon(Weapon &type);
	void attack();
};

#endif

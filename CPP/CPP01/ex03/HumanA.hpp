/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:19:58 by flo               #+#    #+#             */
/*   Updated: 2024/07/15 14:31:28 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA
	#define HUMANA

#include "Weapon.hpp"
#include "string"
#include "iostream"

class HumanA
{
private:
	std::string name;
	Weapon &weapon;
public:
	HumanA(std::string name, Weapon &weapon) :name(name), weapon(weapon) {};
	void attack();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 07:03:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/02 12:42:12 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
protected:
	std::string name;
	AMateria *slots[4];
	AMateria **dropped_materials;
public:
	//	de-/constructors
	Character();
	Character(std::string const & type);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();
	//	member functions
	virtual std::string const & getName() const override;
	virtual void equip(AMateria* m) override;
	virtual void unequip(int idx) override;
	virtual void use(int idx, ICharacter& target) override;
};

#endif
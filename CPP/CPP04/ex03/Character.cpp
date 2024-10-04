/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 07:10:10 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/04 08:09:06 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : dropped_materials(nullptr)
{
	name = "undefined";
	for (int i = 0; i < 4; ++i)
	{
		slots[i] = nullptr;
	}
	std::cout << "A nameless Character named " << name << " was created!"
		<< std::endl;
}

Character::Character(std::string const & name) : dropped_materials(nullptr)
{
	Character::name = name;
	for (int i = 0; i < 4; ++i)
	{
		slots[i] = nullptr;
	}
	std::cout << "A Character named " << Character::name
		<< " was created!" << std::endl;
}

Character::Character(const Character &other)
{
	Character::name = other.name;
	std::cout << "A Character named " << Character::name
		<< " was created!" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
	}
	std::cout << "Character named " << name << " copied" << std::endl;
	return (*this);
}

Character::~Character()
{
	//delete dropped_materials;
	for (int i = 0; i < 4; i++)
	{
		delete slots[i];
		slots[i] = nullptr;
	}
	if (dropped_materials)
	{
		int i = 0;
		while (dropped_materials[i])
		{
			delete dropped_materials[i];
			dropped_materials[i] = nullptr;
			i++;
		}
		delete[] dropped_materials;
	}
	std::cout << "Character named " << Character::name
		<< " destroyed" << std::endl;
}

//	member functions

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (m == nullptr)
	{
		std::cout << "no valid Material to equip " << this->getName()
			<< std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] == nullptr)
		{
			delete slots[i];
			slots[i] = m;
			std::cout << "equipped slot " << i << " from "
				<< this->getName() << " with " << m->getType() << std::endl;
			return;
		}
		if (i == 3)
		{
			delete m;
			m = nullptr;
			std::cout << "All slots from " << this->getName()
				<< " are full, unequip one before!" << std::endl;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || slots[idx] == nullptr)
	{
		std::cout << "Invalid slot index or slot is empty!" << std::endl;
		return;
	}
	int new_size = 0;
	while (dropped_materials && dropped_materials[new_size] != nullptr)
	{
		new_size++;
	}
	AMateria** newDroppedMaterials = new AMateria*[new_size + 2];
	newDroppedMaterials[0] = nullptr;
	for (int i = 0; i < new_size; ++i)
	{
		newDroppedMaterials[i] = dropped_materials[i];
	}
	newDroppedMaterials[new_size] = slots[idx];
	newDroppedMaterials[new_size + 1] = nullptr;

	delete[] dropped_materials;
	dropped_materials = newDroppedMaterials;
	slots[idx] = nullptr;
	std::cout << "unequipped slot " << idx << " from "
		<< this->getName() << std::endl;
}



void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Index out of range" << std::endl;
		return;
	}
	if (this->slots[idx] != nullptr)
	{
		this->slots[idx]->use(target);
	}
	else
	{
		std::cout << "Slot " << idx << " from " << this->getName()
			<< " is empty" << std::endl;
	}
	return;
}

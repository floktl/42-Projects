/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 07:10:10 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/03 13:51:09 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	name = "MaterialSource";
	for (int i = 0; i < 4; ++i)
    {
        slots[i] = nullptr;
    }
	std::cout << name << " was created!" << std::endl;
}

MateriaSource::MateriaSource(std::string const & name)
{
	MateriaSource::name = name;
	for (int i = 0; i < 4; ++i)
    {
        slots[i] = nullptr;
    }
	std::cout << MateriaSource::name << " was created!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	MateriaSource::name = other.name;
	std::cout << MateriaSource::name << " was created!" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		name = other.name;
	}
	std::cout << name << " copied" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        if (slots[i] != nullptr)
        {
            delete slots[i];
            slots[i] = nullptr;
        }
    }
	std::cout << MateriaSource::name << " destroyed" << std::endl;
}

//	member functions

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
    {
        std::cout << "Invalid Materia (nullptr)!" << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (slots[i] == nullptr)
        {
            slots[i] = m->clone();
            std::cout << "Materia " << m->getType()
				<< " learned!" << std::endl;
            delete m;
            return;
        }
    }

    std::cout << "MateriaSource is full, can't learn more Materias."
		<< std::endl;
    delete m;
}



AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 3; i++)
	{
		if (slots[i] && type == this->slots[i]->getType())
		{
			return (this->slots[i]->clone());
		}
	}
	std::cout << "Materia couldnt be created" << std::endl;
    return nullptr;
}
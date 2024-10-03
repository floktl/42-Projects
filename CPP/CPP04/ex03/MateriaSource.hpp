/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 07:03:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/03 13:06:19 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
protected:
	std::string name;
	AMateria *slots[4];
	AMateria **dropped_materials;
public:
	//	de-/constructors
	MateriaSource();
	MateriaSource(std::string const & type);
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();
	//	member functions
	virtual void learnMateria(AMateria*) override;
	virtual AMateria* createMateria(std::string const & type) override;
};

#endif

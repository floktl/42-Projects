/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 07:03:22 by fkeitel           #+#    #+#             */
/*   Updated: 2024/10/02 08:05:22 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria
{
protected:
	std::string type;
public:
	//	de-/constructors
	Cure();
	Cure(std::string const & type);
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	virtual ~Cure();
	//	member functions
	std::string const & getType() const;
	virtual Cure* clone() const override;
	virtual void use(ICharacter& target) override;
};

#endif

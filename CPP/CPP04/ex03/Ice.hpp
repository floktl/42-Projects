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

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria
{
protected:
	std::string type;
public:
	//	de-/constructors
	Ice();
	Ice(std::string const & type);
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	virtual ~Ice();
	//	member functions
	std::string const & getType() const;
	virtual Ice* clone() const override;
	virtual void use(ICharacter& target) override;
};

#endif
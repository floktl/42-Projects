/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:25:30 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/21 13:53:29 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructed!" << std::endl;
}

Brain::Brain(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
	}
	std::cout << "Brain copy constructed!" << std::endl;
}

Brain &Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
		std::cout << "Brain copy assignment constructed!" << std::endl;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain deconstructed!" << std::endl;
}

std::string Brain::getIdeas(int i)
{
	if (i < 100 && i >= 0)
	{
		if (this->ideas[i].empty())
			std::cout << "This thought doesnt exist" << std::endl;
		return (this->ideas[i]);
	}
	return (nullptr);
}

void Brain::setIdeas(int i, std::string idea)
{
	if (i < 100 && i >= 0)
		ideas[i] = idea;
	else
		std::cout << "idea could not be implemented";
}
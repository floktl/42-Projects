/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:26:34 by fkeitel           #+#    #+#             */
/*   Updated: 2024/09/14 08:26:35 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Function to convert a string to uppercase
std::string to_uppercase(const std::string &input)
{
	std::string result = input;
	for (std::string::iterator it = result.begin(); it != result.end(); ++it)
	{
		if (std::islower(*it))
		{
			*it = std::toupper(*it);
		}
	}
	return result;
}

// Function to mimic megaphone behavior
void megaphone(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string arg = argv[i];
			std::cout << to_uppercase(arg);
		}
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	megaphone(argc, argv);
	return 0;
}

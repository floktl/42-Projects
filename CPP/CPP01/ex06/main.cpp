/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:21:41 by flo               #+#    #+#             */
/*   Updated: 2024/07/25 13:22:40 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int main(void)
{
	Harl harl;

	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("TEST");
	harl.complain("");
	return (0);
}

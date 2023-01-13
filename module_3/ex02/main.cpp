/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:06:15 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/04 15:06:15 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	{
		FragTrap alex("Alex");

		alex.attack("Jack");
		alex.takeDamage(6);
		alex.beRepaired(4);
		alex.takeDamage(3);
		alex.highFivesGuys();
		alex.beRepaired(8);
		alex.takeDamage(17);
	}
	std::cout << std::endl;
	{
		ScavTrap steeve("Steeve");

		steeve.attack("Jack");
		steeve.takeDamage(6);
		steeve.beRepaired(4);
		steeve.takeDamage(3);
		steeve.guardGate();
		steeve.beRepaired(8);
		steeve.takeDamage(17);
	}
	std::cout << std::endl;
	{
		ClapTrap sam("Sam");

		sam.attack("Jack");
		sam.takeDamage(6);
		sam.beRepaired(4);
		sam.takeDamage(3);
		sam.beRepaired(8);
		sam.takeDamage(17);
	}
}

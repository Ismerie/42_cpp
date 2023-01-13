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

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"


	int	main( void )
{
	{
		ScavTrap alex("Alex");

		alex.attack("Jack");
		alex.takeDamage(6);
		alex.beRepaired(4);
		alex.takeDamage(3);
		alex.guardGate();
		alex.beRepaired(8);
		alex.takeDamage(17);
	}
	std::cout << std::endl;
	{
		ClapTrap steve("Steve");

		steve.attack("Jack");
		steve.takeDamage(6);
		steve.beRepaired(4);
		steve.takeDamage(3);
		steve.beRepaired(8);
		steve.takeDamage(17);
	}
	return (0);
}

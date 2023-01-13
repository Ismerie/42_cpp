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

int main() {
	ClapTrap claptrap_steve("Steve");
	ClapTrap claptrap_alex("Alex");

	std::cout << std::endl;
	claptrap_steve.attack("Alex");
	claptrap_alex.takeDamage(4);
	claptrap_alex.beRepaired(3);
	claptrap_alex.beRepaired(18);

	claptrap_alex.attack("Steve");
	claptrap_steve.takeDamage(9);
	claptrap_alex.attack("Steve");
	claptrap_steve.takeDamage(9);
	claptrap_alex.attack("Steve");

	claptrap_steve.beRepaired(3);
	claptrap_steve.beRepaired(64);
	std::cout << std::endl;
	return (0);
}
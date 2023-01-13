/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:03:28 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/04 13:03:28 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    std::cout << "Creating the first zombie Lisa manually" << std::endl;
    {
        Zombie  lisa("Lisa");
        lisa.announce();
    }
    std::cout << "Creating the second zombie Alex with the funtion newZombie" << std::endl;
    {
        Zombie  *alex;
        alex = newZombie("Alex");
        alex->announce();
        delete alex;
    }
    std::cout << "Creating the third zombie Sasha with the funtion randomChump" << std::endl;
    {
        randomChump("Sasha");
    }
    return(0);
}

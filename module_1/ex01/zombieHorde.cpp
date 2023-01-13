/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:39:15 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/04 13:39:15 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* tab_zombie = new Zombie[N];
    int     i;

    for (i = 0; i < N; i++)
        tab_zombie[i].set_name(name);
    return  tab_zombie;
}

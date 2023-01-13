/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:39:35 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/04 13:39:35 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
# include <cstdlib>


int main(int argc, char **argv)
{
    Zombie *horde;
    int     N(0);
    int     i;

    if (argc != 3)
    {
        std::cout << "This program needs 2 arguments : number_zombie and name_zombie" << std::endl;
        return(0);
    }
    N = atoi(argv[1]);
    if (N == 0)
    {
        std::cout << "The minimum is 1 zombie" << std::endl;
        return(0);
    }
    horde = zombieHorde(N, argv[2]);
    for (i = 0; i < N; i++)
        horde[i].announce();
    std::cout << std::endl;
    delete [] horde;
    return(0);
}

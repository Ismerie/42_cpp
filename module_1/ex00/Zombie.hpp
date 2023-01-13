/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:56:13 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/04 11:56:13 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
public :
    Zombie(std::string name);
    ~Zombie(void);

    void        announce(void);

private :
    std::string _name;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
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
    Zombie(void);
    ~Zombie(void);

    void        announce(void);
    void        set_name(std::string name);

private :
    std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
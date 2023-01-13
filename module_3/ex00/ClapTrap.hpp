/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:06:28 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/04 15:06:28 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class   ClapTrap {
    public :
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &src);
        ~ClapTrap(void);
    
        ClapTrap    &operator=(const ClapTrap &other);

        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

    private :
        std::string _name;
        unsigned int         _hit_points;
        unsigned int         _energy_points;
        unsigned int         _attack_damage;

};

#endif
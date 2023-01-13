/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:16:12 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/17 14:16:12 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class   ScavTrap : public ClapTrap {
    public :
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &src);
        ~ScavTrap(void);
    
        ScavTrap    &operator=(const ScavTrap &other);

        void    attack(const std::string &target);
        void    guardGate(void);

};

#endif
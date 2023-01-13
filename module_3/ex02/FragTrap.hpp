/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:24:05 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/17 18:24:05 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class   FragTrap : public ClapTrap {
    public :
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &src);
        ~FragTrap(void);
    
        FragTrap    &operator=(const FragTrap &other);

        void    attack(const std::string &target);
        void    highFivesGuys(void);

};

#endif
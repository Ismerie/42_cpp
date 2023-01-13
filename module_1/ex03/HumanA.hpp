/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:59:50 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/04 14:59:50 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class   HumanA {
public :
    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);

    void    attack(void) const;

private :
    std::string _name;
    Weapon      &_weaponRef;
};

#endif
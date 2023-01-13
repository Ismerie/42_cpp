/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:59:52 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/04 14:59:52 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class   HumanB {
public :
    HumanB(std::string name);
    ~HumanB(void);

    void    attack(void) const;
    void    setWeapon(Weapon &weapon);

private :
    std::string _name;
    Weapon      *_weapon;
};

#endif

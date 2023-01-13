/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HmanB.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:59:39 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/04 14:59:39 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
    return ;
}

HumanB::~HumanB(void) {
    return ;
}

void    HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
    return ;
}

void    HumanB::attack(void) const {
    if (this->_weapon == NULL)
        std::cout << this->_name << " doesn't have a weapon to attack" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    return ;
}

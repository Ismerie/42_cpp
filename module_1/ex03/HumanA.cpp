/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:59:41 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/04 14:59:41 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weaponRef(weapon) {
    return ;
}

HumanA::~HumanA(void) {
    return ;
}

void    HumanA::attack(void) const {
    std::cout << this->_name << " attacks with their " << this->_weaponRef.getType() << std::endl;
    return ;
}

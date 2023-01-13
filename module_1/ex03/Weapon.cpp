/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:59:45 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/04 14:59:45 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
    return ;
}

Weapon::~Weapon(void) {
    return ;
}

std::string Weapon::getType(void) const {
    return this->_type;
}

void    Weapon::setType(std::string new_type) {
    this->_type = new_type;
    return ;
}

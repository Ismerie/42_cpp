/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:16:03 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/17 14:16:03 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"
# include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name)  : ClapTrap(name) {
        this->_name = name;
        this->_hit_points = 100;
        this->_energy_points = 50;
        this->_attack_damage = 20;
        std::cout << "Constructor called for ScavTrap" << std::endl;
        return ;
    }

ScavTrap::ScavTrap(void) : ClapTrap() {
        this->_name = "";
        this->_hit_points = 100;
        this->_energy_points = 50;
        this->_attack_damage = 20;
        std::cout << "Constructor called for ScavTrap" << std::endl;
        return ;
    }

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src._name){
    std::cout << "Copy constructor called for ScavTrap" << std::endl;
    *this = src;
    return ;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "Destrcutor called for ScavTrap" << std::endl;
    return ;
}

ScavTrap   &ScavTrap::operator=(ScavTrap const &other) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_points = other._energy_points;
        this->_attack_damage = other._attack_damage;
    }
    return *this;
}

void    ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->_name << " entered Gate Keeper mode !" << std::endl;
    return ;
}

void    ScavTrap::attack(std::string const &target) {
    if (this->_hit_points <= 0) {
        std::cout << "ScavTrap " << this->_name << " cannot attack because he's dead" << std::endl;
        return ;
    }
    else if (this->_energy_points <= 0) {
         std::cout << "ScavTrap " << this->_name << " cannot attack because he has no more energy" << std::endl;
        return ;
    }
    this->_energy_points -= 1;
    std::cout << "ScavTrap " << this->_name << " attacks " << target \
    << ", causing " << this->_attack_damage << " points of damage !" << std::endl;
    return ;
}

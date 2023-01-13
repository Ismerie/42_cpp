/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:06:38 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/04 15:06:38 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hit_points(10),
     _energy_points(10), _attack_damage(0) {
    std::cout << "Constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10),
     _energy_points(10), _attack_damage(0) {
    std::cout << "Constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

ClapTrap   &ClapTrap::operator=(ClapTrap const &other) {
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

void    ClapTrap::attack(const std::string &target) {
    if (this->_hit_points <= 0) {
        std::cout << "ClapTrap " << this->_name << " cannot attack because he's dead" << std::endl;
        return ;
    }
    else if (this->_energy_points <= 0) {
         std::cout << "ClapTrap " << this->_name << " cannot attack because he has no more energy" << std::endl;
        return ;
    }
    this->_energy_points -= 1;
    std::cout << "ClapTrap " << this->_name << " attacks " << target \
    << ", causing " << this->_attack_damage << " points of damage !" << std::endl;
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hit_points <= 0) {
        std::cout << "ClapTrap " << this->_name << " didn't take any damage because he's already dead" << std::endl;
		return ;
    }
    if (amount >= this->_hit_points) {
        this->_hit_points = 0;
        std::cout << "ClapTrap " << this->_name << " took " << amount \
        << " dammage ! He's dead !" << std::endl;
    }
    else {
        this->_hit_points -= amount;
        std::cout << "ClapTrap " << this->_name << " took " << amount \
		<< " hit points, OUCH! Only got " << this->_hit_points \
		<< " hit points left." << std::endl;
    }
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hit_points <= 0) {
        std::cout << "ClapTrap " << this->_name << " can't heal because he's dead" << std::endl;
		return ;
    }
    else {
        this->_hit_points += amount;
        std::cout << "ClapTrap " << this->_name << " was just repaired " \
	    << amount << " hit points, now he's got " << this->_hit_points << std::endl;
    }
    return ;
}

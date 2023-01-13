/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:24:20 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/17 18:24:20 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)  : ClapTrap(name) {
        this->_name = name;
        this->_hit_points = 100;
        this->_energy_points = 100;
        this->_attack_damage = 30;
        std::cout << "Constructor called for FragTrap" << std::endl;
        return ;
    }

FragTrap::FragTrap(void) : ClapTrap() {
        this->_name = "";
        this->_hit_points = 100;
        this->_energy_points = 100;
        this->_attack_damage = 30;
        std::cout << "Constructor called for FragTrap" << std::endl;
        return ;
    }

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src._name){
    std::cout << "Copy constructor called for FragTrap" << std::endl;
    *this = src;
    return ;
}

FragTrap::~FragTrap(void) {
    std::cout << "Destrcutor called for FragTrap" << std::endl;
    return ;
}

FragTrap   &FragTrap::operator=(FragTrap const &other) {
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

void    FragTrap::highFivesGuys(void) {
    std::cout << "Hey guys ! Give me a high five !" << std::endl;
    return ;
}

void    FragTrap::attack(std::string const &target) {
    if (this->_hit_points <= 0) {
        std::cout << "FragTrap " << this->_name << " cannot attack because he's dead" << std::endl;
        return ;
    }
    else if (this->_energy_points <= 0) {
         std::cout << "FragTrap " << this->_name << " cannot attack because he has no more energy" << std::endl;
        return ;
    }
    this->_energy_points -= 1;
    std::cout << "FragTrap " << this->_name << " attacks " << target \
    << ", causing " << this->_attack_damage << " points of damage !" << std::endl;
    return ;
}

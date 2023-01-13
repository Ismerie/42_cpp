/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:18:08 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/18 16:18:08 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Animal.hpp"

Animal::Animal(void) : _type("default") {
    std::cout << "Constructor called for Animal" << std::endl;
    return ;
}

Animal::Animal(const Animal &src) {
    std::cout << "Copy constructor called for Animal" << std::endl;
    *this = src;
    return ;
}

Animal::~Animal(void) {
    std::cout << "Destructor called for Animal" << std::endl;
    return ;
}

Animal   &Animal::operator=(Animal const &other) {
    std::cout << "Copy assignement operator called for Animal" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

std::string Animal::getType(void) const {
    return (this->_type);
}

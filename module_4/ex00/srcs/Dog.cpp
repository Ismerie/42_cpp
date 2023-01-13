/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:20:59 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/18 16:20:59 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Dog.hpp"

Dog::Dog(void) : Animal() {
    this->_type = "Dog";
    std::cout << "Constructor called for Dog" << std::endl;
    return ;
}

Dog::Dog(const Dog &src) : Animal() {
    std::cout << "Copy constructor called for Dog" << std::endl;
    *this = src;
    return ;
}

Dog::~Dog(void) {
    std::cout << "Destructor called for Dog" << std::endl;
    return ;
}

Dog   &Dog::operator=(Dog const &other) {
    std::cout << "Copy assignement operator called for Dog" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void    Dog::makeSound(void) const {
    std::cout << getType() << " says " << "*Wouaf*" << std::endl;
    return ;
}

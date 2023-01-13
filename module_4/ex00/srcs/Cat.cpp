/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:20:53 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/18 16:20:53 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Cat.hpp"

Cat::Cat(void) : Animal() {
    this->_type = "Cat";
    std::cout << "Constructor called for Cat" << std::endl;
    return ;
}

Cat::Cat(const Cat &src) : Animal() {
    std::cout << "Copy constructor called for Cat" << std::endl;
    *this = src;
    return ;
}

Cat::~Cat(void) {
    std::cout << "Destructor called for Cat" << std::endl;
    return ;
}

Cat   &Cat::operator=(const Cat &other) {
    std::cout << "Copy assignement operator called for Cat" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void    Cat::makeSound(void) const {
    std::cout << getType() << " says " << "*Miaou*" << std::endl;
    return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:40:00 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/03 12:40:00 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("wrong default") {
    std::cout << "Constructor called for WrongAnimal" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
    std::cout << "Copy constructor called for WrongAnimal" << std::endl;
    *this = src;
    return ;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "Destructor called for WrongAnimal" << std::endl;
    return ;
}

WrongAnimal   &WrongAnimal::operator=(WrongAnimal const &other) {
    std::cout << "Copy assignement operator called for WrongAnimal" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

std::string WrongAnimal::getType(void) const {
    return (this->_type);
}

void    WrongAnimal::makeSound(void) const {
    std::cout << getType() << " says " << "*WrongAnimal sounds*" << std::endl;
    return ;
}

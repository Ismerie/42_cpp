/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:42:06 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/03 12:42:06 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
    this->_type = "WrongCat";
    std::cout << "Constructor called for WrongCat" << std::endl;
    return ;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal() {
    std::cout << "Copy constructor called for WrongCat" << std::endl;
    *this = src;
    return ;
}

WrongCat::~WrongCat(void) {
    std::cout << "Destructor called for WrongCat" << std::endl;
    return ;
}

WrongCat   &WrongCat::operator=(const WrongCat &other) {
    std::cout << "Copy assignement operator called for WrongCat" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void    WrongCat::makeSound(void) const {
    std::cout << getType() << " says " << "*WrongCat sounds*" << std::endl;
    return ;
}

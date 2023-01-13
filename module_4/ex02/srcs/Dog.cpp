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

/*cerr is standard output stream for errors*/
Dog::Dog(void) : Animal() {
    std::cout << "Constructor called for Dog" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
    return ;
}

Dog::Dog(const Dog &src) : Animal() {
    std::cout << "Copy constructor called for Dog" << std::endl;
    *this = src;
    return ;
}

Dog::~Dog(void) {
    std::cout << "Destructor called for Dog" << std::endl;
    delete this->_brain;
    return ;
}

Dog   &Dog::operator=(Dog const &other) {
    std::cout << "Copy assignement operator called for Dog" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        this->_brain = new Brain();
        *this->_brain = *other._brain;
    }
    return *this;
}

void    Dog::makeSound(void) const {
    std::cout << getType() << " says " << "*Wouaf*" << std::endl;
    return ;
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

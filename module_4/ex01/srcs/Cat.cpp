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

/*cerr is standard output stream for errors*/
Cat::Cat(void) : Animal() {
    std::cout << "Constructor called for Cat" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
    return ;
}

Cat::Cat(const Cat &src) : Animal() {
    std::cout << "Copy constructor called for Cat" << std::endl;
    *this = src;
    return ;
}

Cat::~Cat(void) {
    delete this->_brain;
    std::cout << "Destructor called for Cat" << std::endl;
    return ;
}

Cat   &Cat::operator=(const Cat &other) {
    std::cout << "Copy assignement operator called for Cat" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        this->_brain = new Brain();
        *this->_brain = *other._brain;
    }
    return *this;
}

void    Cat::makeSound(void) const {
    std::cout << getType() << " says " << "*Miaou*" << std::endl;
    return ;
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}

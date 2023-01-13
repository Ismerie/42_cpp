/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:16:23 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/03 13:16:23 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Brain.hpp"

Brain::Brain(void) {
    std::cout << "Constructor called for Brain" << std::endl;
    return ;
}

Brain::Brain(const Brain &src) {
    std::cout << "Copy constructor called for Brain" << std::endl;
    *this = src;
    return ;
}

Brain::~Brain(void) {
    std::cout << "Destructor called for Brain" << std::endl;
    return ;
}

Brain   &Brain::operator=(Brain const &other) {
    std::cout << "Copy assignement operator called for Brain" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
	    {
		    if (other._ideas[i].length() > 0)
			    this->_ideas[i].assign(other._ideas[i]);
	    }
    }
    return *this;
}

std::string	Brain::getIdeas(size_t i) const
{
	if (i < 100)
		return(this->_ideas[i]);
	else
		return ("\033[33mThere is only 100 ideas per brain.\033[0m");
}

void	Brain::setIdeas(size_t i, std::string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "\033[33mThere is only 100 ideas per brain.\033[0m" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:33:31 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/31 16:33:31 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Intern.hpp"

Intern::Intern() {
    std::cout << "Default constructor called for Intern" << std::endl;
    return ;
}

Intern::Intern(const Intern &src) {
    std::cout << "Copy constructor called for Intern" << std::endl;
    *this = src;
    return ;
}

Intern::~Intern(void) {
    std::cout << "Destructor called for Intern" << std::endl;
    return ;
}

Intern   &Intern::operator=(Intern const &other) {
    std::cout << "Copy assignement operator called for Intern" << std::endl;
     if (this != &other) {
        return *this;
    }
    return *this;
}

// Functions

Form    *Intern::makeForm(std::string name, std::string target) {
    std::string forms[3] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    Form    *result = NULL;
    int     i = 0;

    for (i = 0; i < 3; i++) {
        if (name == forms[i])
            break ;
    }
    switch (i) {
        case 0 :
            result = new ShrubberyCreationForm(target);
            break;
        case 1 :
            result = new RobotomyRequestForm(target);
            break;
        case 2 :
            result = new PresidentialPardonForm(target);
            break;
        default :
            std::cout << "/!\\ Intern was not able to find the form " << name << std::endl;
            return result;
    }
	std::cout << "Intern creates form " << name << std::endl;
	return result;

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:54:28 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/29 17:54:28 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Shrub Parent", 25, 5) {
    _target = target;
    std::cout << "Constructor called for PresidentialPardonForm" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm() : Form("Default Shrub Parent", 25, 5) {
    _target = "Default";
    std::cout << "Default constructor called for PresidentialPardonForm" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : 
    Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
	_target = src._target;
	std::cout << "Copy constructor called for PresidentialPardonForm" << std::endl;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called for PresidentialPardonForm" << std::endl;
    return ;
}

PresidentialPardonForm   &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    std::cout << "Copy assignement operator called for PresidentialPardonForm" << std::endl;
    if (this != &other) {
        _target = other.getTarget();
    }
    return *this;
}

//Getters
std::string PresidentialPardonForm::getTarget() const {
    return (_target);
}

//Functions
void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (this->getSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
    else
		std::cout << _target << " was pardonned by Zafod Beeblebrox\n";
    return ;
}

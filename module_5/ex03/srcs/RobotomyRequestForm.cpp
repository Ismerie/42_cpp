/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:54:14 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/29 17:54:14 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Shrub Parent", 72, 45) {
    _target = target;
    std::cout << "Constructor called for RobotomyRequestForm" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm() : Form("Default Shrub Parent", 72, 45) {
    _target = "Default";
    std::cout << "Default constructor called for RobotomyRequestForm" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : 
    Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
	_target = src._target;
	std::cout << "Copy constructor called for RobotomyRequestForm" << std::endl;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called for RobotomyRequestForm" << std::endl;
    return ;
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    std::cout << "Copy assignement operator called for RobotomyRequestForm" << std::endl;
    if (this != &other) {
        _target = other.getTarget();
    }
    return *this;
}

//Getters
std::string RobotomyRequestForm::getTarget() const {
    return (_target);
}

//Functions
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (this->getSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());

    int success = std::rand() % 2; //random number 0 or 1

    std::cout << "*VRRR BZZZ VRRR BZZZ*" << std::endl;
    if (success == 1)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomization is a failure" << std::endl;
    return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:54:16 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/29 17:54:16 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrub Parent", 145, 137) {
    _target = target;
    std::cout << "Constructor called for ShrubberyCreationForm" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Default Shrub Parent", 145, 137) {
    _target = "Default";
    std::cout << "Default constructor called for ShrubberyCreationForm" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : 
    Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
	_target = src._target;
	std::cout << "Copy constructor called for ShrubberyCreationForm" << std::endl;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called for ShrubberyCreationForm" << std::endl;
    return ;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    std::cout << "Copy assignement operator called for ShrubberyCreationForm" << std::endl;
    if (this != &other) {
        _target = other.getTarget();
    }
    return *this;
}

//Getters
std::string ShrubberyCreationForm::getTarget() const {
    return (_target);
}

//Functions
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    std::string	        tree = 
    "     OOooOoOo          \n"
    "  OoOooOOOooOOOOooO    \n"
    " ooOOOoooOOoOoOOOOooO  \n"
    "OOooOoOoOOO   OoooOOooO\n"
    "   OOoo  OOoO OoOooOOo \n"
    "      \\\\//  /OOooO   \n"
    "        \\\\////       \n"
    "         |||/\\        \n"
    "         |||\\/        \n"
    "         |||||         \n"
    "  .....\\//||||\\....  \n";

    if(this->getSigned() == false)
        throw (Form::UnsignedFormException());
    else if (executor.getGrade() > this->getGradeToExecute())
        throw (Form::GradeTooLowException());
    else {
        std::ofstream ofs;

        if (ofs.is_open())
            ofs.close();
        ofs.open(std::string(this->_target + "_shrubbery").c_str());
        if (!ofs.is_open() || ofs.bad() || ofs.fail()) {
            std::cout << "Couldn't open the output file" << std::endl;
            return ;
        }
        ofs << tree;
        ofs.close();
    }
    return ;
}

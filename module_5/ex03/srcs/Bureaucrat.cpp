/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:24:22 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/28 16:24:22 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else
        _grade = grade;
    std::cout << "Constructor called for Bureaucrat" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << "Default constructor called for Bureaucrat" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
    std::cout << "Copy constructor called for Bureaucrat" << std::endl;
    *this = src;
    return ;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Destructor called for Bureaucrat" << std::endl;
    return ;
}

Bureaucrat   &Bureaucrat::operator=(Bureaucrat const &other) {
    std::cout << "Copy assignement operator called for Bureaucrat" << std::endl;
    if (this != &other) {
        _grade = other.getGrade();
    }
    return *this;
}

// Functions
void    Bureaucrat::incrementGrade() {
    std::cout << "Decrementing bureaucrat " << _name << "'s grade " << _grade << " by 1" << std::endl;
    if (_grade == 1)
        throw (Bureaucrat::GradeTooHighException());
    else
        _grade--;
    return ;
}

void    Bureaucrat::decrementGrade() {
    std::cout << "Decrementing bureaucrat " << _name << "'s grade " << _grade << " by 1" << std::endl;
    if (_grade == 150)
        throw (Bureaucrat::GradeTooLowException());
    else
        _grade++;
    return ;
}

void    Bureaucrat::signForm(Form &src) {
    try
	{
		src.beSigned(*this);
		std::cout << "Bureaucrat " << _name << " with a grade " << _grade << " succesfully signs " << src << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat " << _name << " with a grade " << _grade << " cannot sign " << src 
            << " because " << e.what() << std::endl;
	}
    return ;
}

void    Bureaucrat::executeForm(const Form &src) {
    try
	{
		src.execute(*this);
		std::cout << "Bureaucrat " << _name << " succesfully executed" << src << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    return ;
}

// Getters
const std::string   Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

// Setters
void    Bureaucrat::setGrade(const int new_grade) {
    if (new_grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (new_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else
        _grade = new_grade;
    std::cout << "Bureaucrat " << _name << "'s grade was set to " << new_grade << std::endl;
    return ;
}

// << operator overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
    out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return (out);
}

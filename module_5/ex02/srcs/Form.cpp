/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:08:13 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/29 00:08:13 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name),  _signed(0),
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw (Form::GradeTooLowException());
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw (Form::GradeTooHighException());
    else 
        std::cout << "Constructor called for Form" << std::endl;
    return ;
}

Form::Form() : _name("Default"), _signed(0), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Default constructor called for Form" << std::endl;
    return ;
}

Form::Form(const Form &src) : _name(src._name), 
    _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)  {
    std::cout << "Copy constructor called for Form" << std::endl;
    *this = src;
    return ;
}

Form::~Form(void) {
    std::cout << "Destructor called for Form" << std::endl;
    return ;
}

Form   &Form::operator=(Form const &other) {
    std::cout << "Copy assignement operator called for Form" << std::endl;
    if (this != &other) {
        _signed = other.getSigned();
    }
    return *this;
}

// Functions
void    Form::beSigned(Bureaucrat &src) {
    int	grade = src.getGrade();

	if (grade > _gradeToSign)
	{
		throw (Form::GradeTooLowException());
		return ;
	}
	_signed = true;
	std::cout << *this << " was just signed by the bureaucrat " << src.getName() << " with a grade " 
        << src.getGrade() << std::endl;
    return ;
}

// Getters
const std::string   &Form::getName() const {
    return (this->_name);
}

const bool    &Form::getSigned() const {
    return (this->_signed);
}

const int   &Form::getGradeToSign() const {
    return (this->_gradeToSign);
}

const int   &Form::getGradeToExecute() const {
    return (this->_gradeToExecute);
}

// Setters
void    Form::setSigned(bool value) {
    std::cout << _name << " Form signed value was set to " << value << std::endl;
    _signed = value;
    return ;
}

// << operator overload
std::ostream &operator<<(std::ostream &out, const Form &src) {
    out << "Form " << src.getName() << " having a grade to sign " << src.getGradeToSign()
        << " and a grade to execute " << src.getGradeToExecute() << " with signed equal to " << src.getSigned();
    return (out);
}
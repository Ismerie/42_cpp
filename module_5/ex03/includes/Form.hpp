/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:08:17 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/29 00:08:17 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>
# include <stdexcept>
class   Form;
# include "Bureaucrat.hpp"

class   Form {
    public :
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form();
        Form(const Form &src);
        virtual ~Form();

        Form    &operator=(const Form &other);
    
        void    beSigned(Bureaucrat &src);
        virtual void    execute(const Bureaucrat &executor) const = 0;

        const std::string   &getName() const;
        const bool          &getSigned() const;
        const int           &getGradeToSign() const;
        const int           &getGradeToExecute() const;

        void                setSigned(bool value);

        // Nested Exception classes
        class GradeTooHighException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return ("FormException: Grade is too high");
                }
        };

        class GradeTooLowException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return ("FormExeption: Grade is too low");
                }
        };

        class UnsignedFormException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return ("FormException: Unsigned form can't be executed");
                }
        };

    private :
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif
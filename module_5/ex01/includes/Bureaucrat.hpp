/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:24:20 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/28 16:24:20 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
# include <stdexcept>
class   Bureaucrat;
# include "Form.hpp"

class   Bureaucrat {
    public :
        Bureaucrat(std::string name, int grade);
        Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        virtual ~Bureaucrat(void);
    
        Bureaucrat    &operator=(const Bureaucrat &other);

        const std::string   getName() const;
        int                 getGrade() const;
        void                setGrade(const int new_grade);

        void    incrementGrade();
        void    decrementGrade();
        void    signForm(Form &src);

        // Nested Exception classes
        class Exception : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return ("BureaucratException");
                }
        };

        class GradeTooHighException : public Bureaucrat::Exception {
            public :
                virtual const char* what() const throw() {
                    return ("Bureaucrat cannot get a grade < 1");
                }
        };

        class GradeTooLowException : public Bureaucrat::Exception {
            public :
                virtual const char* what() const throw() {
                    return ("Bureaucrat cannot get a grade > 150");
                }
        };

    private :
        const std::string           _name;
        int                         _grade;

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);

#endif

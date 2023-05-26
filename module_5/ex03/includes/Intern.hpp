/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:32:35 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/31 16:32:35 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class   Intern {
    public :
        Intern();
        Intern(const Intern &src);
        virtual ~Intern(void);
    
        Intern    &operator=(const Intern &other);

        Form    *makeForm(std::string name, std::string target);
};

#endif
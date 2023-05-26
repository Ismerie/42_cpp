/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:54:20 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/29 17:54:20 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>

class   RobotomyRequestForm : public Form {
    public : 
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

        std::string getTarget() const;

        void    execute(const Bureaucrat &executor) const;
    
    private :
        std::string _target;
};

#endif
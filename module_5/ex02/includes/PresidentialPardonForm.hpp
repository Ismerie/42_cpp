/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:54:18 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/29 17:54:18 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class   PresidentialPardonForm : public Form {
    public : 
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &src);
        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

        std::string getTarget() const;

        void    execute(const Bureaucrat &executor) const;
    
    private :
        std::string _target;
};

#endif
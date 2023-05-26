/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:54:22 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/29 17:54:22 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class   ShrubberyCreationForm : public Form {
    public : 
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

        std::string getTarget() const;

        void    execute(const Bureaucrat &executor) const;
    
    private :
        std::string _target;
};

#endif
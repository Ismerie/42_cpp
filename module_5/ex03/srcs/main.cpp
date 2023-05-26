/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:24:25 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/28 16:24:25 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Bureaucrat.hpp"
# include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
# include "../includes/Intern.hpp"

int	main(void)
{
	try
	{
		Intern someRandomIntern;
		Form *rtn;

		rtn = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
//		rtn = someRandomIntern.makeForm("wrongForm", "mjung");
		std::cout << rtn->getName() << std::endl;
		//std::cout << rtn->getTarget() << std::endl;

		std::cout << *rtn << std::endl;
		if (rtn)
			delete rtn;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
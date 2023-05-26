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

int main() {
	std::cout << "CONSTRUCTING WITH GRADE -49:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		Bureaucrat bill("Bill", -49);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;
	

	std::cout << "CONSTRUCTING WITH GRADE 256:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		Bureaucrat bill("Bill", 256);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;


	// Normal increment/decrement and "<<" overload
	std::cout << "IN/DECREMENT + \"<<\" overload:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Bureaucrat bob("Bob", 1);
	try
	{
		bob.decrementGrade();
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;


	// Increment 1 exception
	std::cout << "INCREMENT GRADE 1:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;


	std::cout << "DECREMENT GRADE 150:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	bob.setGrade(150);
	try
	{
		bob.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl << std::endl;

	
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:34:48 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/16 12:34:48 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int	main( void )
{
	std::cout << "------------INT ARRAY-------------" << std::endl;
	{
		Array<int>	defaultArray;
		Array<int>	intArray(5);

		intArray[0] = 42;
		intArray[1] = 27;
		intArray[2] = 96;
		intArray[3] = 2;

		Array<int>	copieArray(intArray);
		Array<int>	assignArray;
		assignArray = intArray;

		std::cout << std::endl << "        Size Array      " << std::endl;
		std::cout << "defaultArray.size() = " << defaultArray.size() << std::endl;
		std::cout << "intArray.size() = " << intArray.size() << std::endl;
		std::cout << "copieArray.size() = " << copieArray.size() << std::endl;
		std::cout << "assigntArray.size() = " << assignArray.size() << std::endl << std::endl;
		
		std::cout << "        Value index 2      " << std::endl;
		std::cout << "intArray[2] : " << intArray[2] << std::endl;
		std::cout << "copieArray[2] : " << copieArray[2] << std::endl;
		std::cout << "assignArray[2] : " << assignArray[2] << std::endl << std::endl;
		
		std::cout << "         Modify intArray[2] = 1       " << std::endl;
		intArray[2] = 1;
		std::cout << "intArray[2] : " << intArray[2] << std::endl;
		std::cout << "copieArray[2] : " << copieArray[2] << std::endl;
		std::cout << "assignArray[2] : " << assignArray[2] << std::endl << std::endl;

		try
		{
			std::cout << intArray[59] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::cout << intArray[-3] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
	}
	std::cout << std::endl << "------------STRING ARRAY-------------" << std::endl;
	{
		Array<std::string>	defaultArray;
		Array<std::string>	stringArray(5);

		stringArray[0] = "Hi";
		stringArray[1] = "Hello";
		stringArray[2] = "How are you?";
		stringArray[3] = "Doing great thanks!";

		Array<std::string>	copieArray(stringArray);
		Array<std::string>	assignArray;
		assignArray = stringArray;

		std::cout << std::endl << "        Size Array      " << std::endl;
		std::cout << "defaultArray.size() = " << defaultArray.size() << std::endl;
		std::cout << "stringArray.size() = " << stringArray.size() << std::endl;
		std::cout << "copieArray.size() = " << copieArray.size() << std::endl;
		std::cout << "assigntArray.size() = " << assignArray.size() << std::endl << std::endl;
		
		std::cout << "        Value index 2      " << std::endl;
		std::cout << "stringArray[2] : " << stringArray[2] << std::endl;
		std::cout << "copieArray[2] : " << copieArray[2] << std::endl;
		std::cout << "assignArray[2] : " << assignArray[2] << std::endl << std::endl;
		
		std::cout << "         Modify stringArray[2] = You're welcome       " << std::endl;
		stringArray[2] = "You're welcome";
		std::cout << "stringArray[2] : " << stringArray[2] << std::endl;
		std::cout << "copieArray[2] : " << copieArray[2] << std::endl;
		std::cout << "assignArray[2] : " << assignArray[2] << std::endl << std::endl;

		try
		{
			std::cout << stringArray[59] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			std::cout << stringArray[-3] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
	}
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:49:03 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/15 20:49:03 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../includes/iter.hpp"

template<typename T>
void	display( T &value )
{
	std::cout << "Variable's value is: " << value << std::endl;
    return ;
}

int	main()
{
	std::string strTab[3];
	int			intTab[4];

	strTab[0] = "Hi how are you?";
	strTab[1] = "Fine, and you dear sir?";
	strTab[2] = "Very fine indeed!";
	
	intTab[0] = 42;
	intTab[1] = 2;
	intTab[2] = 87;
	intTab[3] = 55;

    std::cout << "-------STRING TAB---------" << std::endl;
	::iter(strTab, 3, &display);

	std::cout << std::endl << "-------INT TAB---------" << std::endl;
	::iter(intTab, 4, &display);
    return 0; 
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:20:46 by igeorge           #+#    #+#             */
/*   Updated: 2022/10/24 18:20:46 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cctype> // toupper
#include <string>

int	main(int argc, char **argv)
{
	int		i(0);
	int		y(0);
	char	c;

	(void)argc;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (i = 1; argv[i]; i++)
	{
		for (y = 0; argv[i][y]; y++)
		{
			c = std::toupper(static_cast<unsigned char>(argv[i][y]));
			std::cout << c;
		}
	}
	std::cout << std::endl;
	return (0);
}

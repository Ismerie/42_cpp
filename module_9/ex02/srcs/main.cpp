/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:30:50 by igeorge           #+#    #+#             */
/*   Updated: 2023/04/17 18:30:50 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		std::cout << "Error: gettimeofday" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

int	main(int argc, char **argv)
{
	PmergeMe								my_sort;
	long long								begin;
	long long								end;
	std::vector<long long>::const_iterator	it_vector;
	std::deque<long long>::const_iterator	it_deque;

	if (argc < 2)
	{
		std::cout << "Error: bad arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	if (!my_sort.checkInput(argv + 1))
	{
		std::cout << "Error: bad input" << std::endl;
		return (EXIT_FAILURE);
	}

	std::cout << "Before: ";
	for (int i = 1; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	
	
	begin = get_time();
	my_sort.sortVec(argc, argv);
	end = get_time();
	std::cout << "After: ";
	for (it_vector = my_sort.getVector().begin(); it_vector != my_sort.getVector().end(); it_vector++)
		std::cout << *it_vector << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << my_sort.getVector().size() <<
		" elements with std::vector : " << end - begin << " us" << std::endl;
	
	
	begin = get_time();
	my_sort.sortDeq(argc, argv);
	end = get_time();
	std::cout << "Time to process a range of " << my_sort.getDeque().size() <<
		" elements with std::deque : " << end - begin << " us" << std::endl;
	return (EXIT_SUCCESS);
}
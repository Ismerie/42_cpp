/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:05:09 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/18 14:05:09 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

void displaySpan(std::string const &name, Span &span)
{
	std::cout << name << "     shortest = "
			<< span.shortestSpan() << "     longest = "
			<< span.longestSpan() << std::endl << std::endl;
}

int main() {
    srand(time(NULL));

	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	displaySpan("Simple", sp);

	Span spcopy = sp;
	displaySpan("Simple (Copy)", spcopy);

	Span spfifty = Span(50);
	for (int i = 0; i < 50; i++)
		spfifty.addNumber(i);
	displaySpan("0 to 49 (included)", spfifty);

	Span sphard = Span(50);
	sphard.addNumber(2);
	sphard.addNumber(39);
	sphard.addNumber(6);
	sphard.addNumber(12);
	sphard.addNumber(7);
	sphard.addNumber(9);
	sphard.addNumber(54);
	displaySpan("[2, 5, 6, 12, 7, 9, 54] -> [1, 52]", sphard);

	Span spzeroone = Span(2);
	spzeroone.addNumber(0);
	spzeroone.addNumber(1);
	displaySpan("0 and 1", spzeroone);

	for (int i = 0; i < 10; i++)
	{
		Span sprandom(900000);
		for (int i = 0; i < 900000; i++)
			sprandom.addNumber((rand() % 100000) - 50000);
		displaySpan("Random", sprandom);
	}

	std::cout << std::endl << "----------Iterator range----------" << std::endl;
	try {
		Span				spaniterator(10);
		std::vector<int>	vect;

		vect.push_back(25);
		vect.push_back(5);
		vect.push_back(12);
		vect.push_back(90);
		vect.push_back(-2);
		spaniterator.addByIteratorRange(vect.begin(), vect.end());
		displaySpan("[25, 5, 12, 90, -2] -> [7, 92]", spaniterator);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "-----------Exceptions---------" << std::endl;
	try
	{
		Span spexception(5);
		spexception.addNumber(1);
		std::cout << spexception.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		Span spexception(10);
		spexception.addNumber(7);
		std::cout << spexception.longestSpan() << std::endl;;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		Span spexception(3);
		spexception.addNumber(4);
        spexception.addNumber(9);
        spexception.addNumber(47);
        spexception.addNumber(4);
		displaySpan("Exception", spexception);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;
	return (0);
}
